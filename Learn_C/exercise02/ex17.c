#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512                //每个字段的最大数据长度
#define MAX_ROWS 100                //数据库中最大的记录的数

//单个地址的记录
struct Address {
    int id;                         //地址编号
    int set;                        //标记是否被设置
    char name[MAX_DATA];            //存储名字的字符数组
    char email[MAX_DATA];           //存储电子邮件地址的字符数组
};

//数据库，包含多个地址
struct Database {
    struct Address rows[MAX_ROWS];  //存储所有地址记录的数组
};

//数据库链接
struct Connection {
    FILE *file;                     //指向文件的指针
    struct Database *db;            //指向Database的指针
};

//错误处理
void die(const char *message)
{
    if(errno) {
        perror(message);            //如果有错误号，打印系统错误信息
    } else {                        //否则打印自定义错误信息
        printf("ERROR: %s\n", message);
    }

    exit(1);                        //退出程序
}

//打印地址记录
void Address_print(struct Address *addr)
{
    printf("%d %s %s\n",            //打印地址记录的ID，名字和电子邮件
            addr->id, addr->name, addr->email);
}

//从文件读取
void Database_load(struct Connection *conn)
{
    //从文件中读取数据库内容
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("读取失败");
}

//建立连接
struct Connection *Database_open(const char *filename, char mode)
{
    //分配内存给连接对象
    struct Connection *conn = malloc(sizeof(struct Connection));    
    if(!conn) die("分配失败");

    //分配内存给数据库对象
    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die("分配失败");

    if(mode == 'c') {
        conn->file = fopen(filename, "w");  //以写模式创建文件
    } else {
        conn->file = fopen(filename, "r+"); //以读写打开文件

        if(conn->file) {
            Database_load(conn);            //加载数据库
        }
    }

    if(!conn->file) die("打开文件失败");      //打开文件失败则退出

    return conn;                            //返回连接对象
}

//关闭并释放内存
void Database_close(struct Connection *conn)
{
    if(conn) {
        if(conn->file) fclose(conn->file);  //如果文件指针存在，关闭文件
        if(conn->db) free(conn->db);        //如果数据库指针存在，释放内存
        free(conn);                         //释放连接对象内存
    }
}

//将数据库写入文件
void Database_write(struct Connection *conn)
{
    rewind(conn->file);                     //将文件指针重置到文件开头

    //将数据库写入文件
    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("写入失败");

    rc = fflush(conn->file);//刷新文件缓冲区
    if(rc == -1) die("刷新失败");
}

//创建空的数据库
void Database_create(struct Connection *conn)
{
    int i = 0;

    for(i = 0; i < MAX_ROWS; i++) {
        struct Address addr = {.id = i, .set = 0};  //初始化每个地址记录
        conn->db->rows[i] = addr;                   //将初始化后的记录存入数据库
    }
}

//设置地址记录
void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
    struct Address *addr = &conn->db->rows[id];     //获取指定id的地址记录
    if(addr->set) die("记录已经设置");

    addr->set = 1;                                  //标记记录为已经设置
    char *res = strncpy(addr->name, name, MAX_DATA);//复制名字到记录中
    if(!res) die("复制名字失败");
    res = strncpy(addr->email, email, MAX_DATA);    //复制电子邮件到记录中
    if(!res) die("复制邮件失败");
}

//获取并打印地址记录
void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];     //获取指定id的地址记录

    if(addr->set) {
        Address_print(addr);                        //如果被设置，打印信息
    } else {
        die("ID未设置");
    }
}

//删除地址记录
void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id = id, .set = 0};     //初始化
    conn->db->rows[id] = addr;                      //用未设置的记录覆盖指定id的记录
}

//列出所有已设置的地址记录
void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];         //获取当前记录

        if(cur->set) {
            Address_print(cur);                     //如果已设置，打印记录
        }
    }
}

int main(int argc, char *argv[])
{
    //如果参数不足，调用die函数
    if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");

    char *filename = argv[1];               //数据库文件名
    char action = argv[2][0];               //获取操作类型
    struct Connection *conn = Database_open(filename, action);  //打开数据库
    int id = 0;

    if(argc > 3) id = atoi(argv[3]);        //获取id
    if(id >= MAX_ROWS) die("超出范围");      //如果id超出范围，调用die函数

    switch(action) {
        case 'c'://创建数据库
            Database_create(conn);
            Database_write(conn);
            break;

        case 'g'://获取记录
            if(argc != 4) die("需要 id 才能获取");//如果参数不足，调用die函数

            Database_get(conn, id);
            break;

        case 's'://设置记录
            if(argc != 6) die("需要id，name，email来设置");

            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd'://删除记录
            if(argc != 4) die("删除需要id");

            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l'://列出所有记录
            Database_list(conn);
            break;
        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");
    }

    Database_close(conn);

    return 0;
}


