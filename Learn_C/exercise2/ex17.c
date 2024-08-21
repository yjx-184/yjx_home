// #include <stdio.h>
// #include <assert.h>
// #include <stdlib.h>
// #include <errno.h>
// #include <string.h>

// #define MAX_DATA 512    //每个字段的最大数据长度
// #define MAX_ROWS 100    //数据库中最大的记录的数

// //单个地址的记录
// struct Address {
//     int id;
//     int set;
//     char name[MAX_DATA];
//     char email[MAX_DATA];
// };

// //数据库，包含多个地址
// struct Database {
//     struct Address rows[MAX_ROWS];
// };

// //数据库链接
// struct Connection {
//     FILE *file;//指向文件的指针
//     struct Database *db;//指向Database的指针
// };

// //错误处理
// void die(const char *message)
// {
//     if(errno) {
//         perror(message);
//     } else {
//         printf("ERROR: %s\n", message);
//     }

//     exit(1);
// }

// //打印
// void Address_print(struct Address *addr)
// {
//     printf("%d %s %s\n",
//             addr->id, addr->name, addr->email);
// }

// //从文件读取
// void Database_load(struct Connection *conn)
// {
//     int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
//     if(rc != 1) die("读取失败");
// }

// //建立连接
// struct Connection *Database_open(const char *filename, char mode)
// {
//     struct Connection *conn = malloc(sizeof(struct Connection));
//     if(!conn) die("分配失败");

//     conn->db = malloc(sizeof(struct Database));
//     if(!conn->db) die("分配失败");

//     if(mode == 'c') {
//         conn->file = fopen(filename, "w");//以写模式创建文件
//     } else {
//         conn->file = fopen(filename, "r+");//以读写打开文件

//         if(conn->file) {
//             Database_load(conn);//加载数据库
//         }
//     }

//     if(!conn->file) die("打开文件失败");//打开文件失败则退出

//     return conn;
// }

// //关闭并释放内存
// void Database_close(struct Connection *conn)
// {
//     if(conn) {
//         if(conn->file) fclose(conn->file);
//         if(conn->db) free(conn->db);
//         free(conn);
//     }
// }

// //写入
// void Database_write(struct Connection *conn)
// {
//     rewind(conn->file);

//     int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
//     if(rc != 1) die("写入失败");

//     rc = fflush(conn->file);//刷新文件缓冲区
//     if(rc == -1) die("刷新失败");
// }

// //创建空的数据库
// void Database_create(struct Connection *conn)
// {
//     int i = 0;

//     for(i = 0; i < MAX_ROWS; i++) {
//         struct Address addr = {.id = i, .set = 0};
//         conn->db->rows[i] = addr;
//     }
// }

// //设置地址记录
// void Database_set(struct Connection *conn, int id, const char *name, const char *email)
// {
//     struct Address *addr = &conn->db->rows[id];
//     if(addr->set) die("记录已经设置");

//     addr->set = 1;
//     char *res = strncpy(addr->name, name, MAX_DATA);
//     if(!res) die("复制名字失败");
//     res = strncpy(addr->email, email, MAX_DATA);
//     if(!res) die("复制邮件失败");
// }

// //获取并打印地址记录
// void Database_get(struct Connection *conn, int id)
// {
//     struct Address *addr = &conn->db->rows[id];

//     if(addr->set) {
//         Address_print(addr);
//     } else {
//         die("ID未设置");
//     }
// }

// //删除
// void Database_delete(struct Connection *conn, int id)
// {
//     struct Address addr = {.id = id, .set = 0};//初始化
//     conn->db->rows[id] = addr;
// }

// void Database_list(struct Connection *conn)
// {
//     int i = 0;
//     struct Database *db = conn->db;

//     for(i = 0; i < MAX_ROWS; i++) {
//         struct Address *cur = &db->rows[i];

//         if(cur->set) {
//             Address_print(cur);
//         }
//     }
// }

// int main(int argc, char *argv[])
// {
//     if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");

//     char *filename = argv[1];//数据库文件名
//     char action = argv[2][0];
//     struct Connection *conn = Database_open(filename, action);
//     int id = 0;

//     if(argc > 3) id = atoi(argv[3]);//获取id
//     if(id >= MAX_ROWS) die("超出范围");

//     switch(action) {
//         case 'c'://创建数据库
//             Database_create(conn);
//             Database_write(conn);
//             break;

//         case 'g'://获取记录
//             if(argc != 4) die("需要 id 才能获取");

//             Database_get(conn, id);
//             break;

//         case 's'://设置记录
//             if(argc != 6) die("需要id，name，email来设置");

//             Database_set(conn, id, argv[4], argv[5]);
//             Database_write(conn);
//             break;

//         case 'd'://删除记录
//             if(argc != 4) die("删除需要id");

//             Database_delete(conn, id);
//             Database_write(conn);
//             break;

//         case 'l':
//             Database_list(conn);
//             break;
//         default:
//             die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");
//     }

//     Database_close(conn);

//     return 0;
// }


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//单个地址的记录
struct Address {
    int id;
    int set;
    char *name;
    char *email;
};

//数据库，包含多个地址
//使其接收参数作为MAX_DATA和MAX_ROWS，将它们储存在Database结构体中
//并且将它们写到文件。这样就可以创建任意大小的数据库。
struct Database {
    int MAX_DATA;
    int MAX_ROWS;
    struct Address *rows;
};

//数据库链接
struct Connection {
    FILE *file;//指向文件的指针
    struct Database *db;//指向Database的指针
};

//错误处理,die函数需要接收conn变量作为参数，以便执行清理并关闭它。
void die(const char *message, struct Connection *conn)
{
    if (conn) {
        if (conn->db) {
            if (conn->db->rows) free(conn->db->rows);
            free(conn->db);
        }
        if (conn->file) fclose(conn->file);
        free(conn);
    }

    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

//打印
void Address_print(struct Address *addr)
{
    printf("%d %s %s\n",
            addr->id, addr->name, addr->email);
}

//从文件读取
void Database_load(struct Connection *conn)
{
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("读取失败", conn);
}

//建立连接
struct Connection *Database_open(const char *filename, char mode)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("分配失败", conn);

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die("分配失败", conn);

    if(mode == 'c') {
        conn->file = fopen(filename, "w");//以写模式创建文件
    } else {
        conn->file = fopen(filename, "r+");//以读写打开文件

        if(conn->file) {
            Database_load(conn);//加载数据库
        }
    }

    if(!conn->file) die("打开文件失败", conn);//打开文件失败则退出

    return conn;
}

//关闭并释放内存
void Database_close(struct Connection *conn)
{
    if(conn) {
        if(conn->file) fclose(conn->file);
        if(conn->db) free(conn->db);
        free(conn);
    }
}

//写入
void Database_write(struct Connection *conn)
{
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("写入失败", conn);

    rc = fflush(conn->file);//刷新文件缓冲区
    if(rc == -1) die("刷新失败", conn);
}

//创建空的数据库
void Database_create(struct Connection *conn)
{
    int i = 0;

    for(i = 0; i < conn->db->MAX_ROWS; i++) {
        struct Address addr = {.id = i, .set = 0};
        conn->db->rows[i] = addr;
    }
}

//设置地址记录
void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
    struct Address *addr = &conn->db->rows[id];
    if(addr->set) die("记录已经设置", conn);

    addr->set = 1;
    char *res = strncpy(addr->name, name, conn->db->MAX_DATA);
    if(!res) die("复制名字失败", conn);
    res = strncpy(addr->email, email, conn->db->MAX_DATA);
    if(!res) die("复制邮件失败", conn);
}

//获取并打印地址记录
void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];

    if(addr->set) {
        Address_print(addr);
    } else {
        die("ID未设置", conn);
    }
}

//删除
void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id = id, .set = 0};//初始化
    conn->db->rows[id] = addr;
}

//查找并打印符合条件的记录
void Database_find(struct Connection *conn, const char *search_term)
{
    int i = 0;
    struct Database *db = conn->db;
    int found = 0;

    for (i = 0; i < db->MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if(cur->set && 
           (strstr(cur->name, search_term) || strstr(cur->email, search_term))) {
            Address_print(cur);
            found = 1;
        }
    }

    if (!found) {
        printf("没有找到符合条件的记录。\n");
    }
}

void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < db->MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if(cur->set) {
            Address_print(cur);
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]", NULL);

    char *filename = argv[1];//数据库文件名
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    int id = 0;

    if(argc > 3) id = atoi(argv[3]);//获取id
    if(id >= conn->db->MAX_ROWS) die("超出范围", conn);

    switch(action) {
        case 'c'://创建数据库
            Database_create(conn);
            Database_write(conn);
            break;

        case 'g'://获取记录
            if(argc != 4) die("需要 id 才能获取", conn);

            Database_get(conn, id);
            break;

        case 's'://设置记录
            if(argc != 6) die("需要id，name，email来设置", conn);

            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd'://删除记录
            if(argc != 4) die("删除需要id", conn);

            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;

        case 'f'://查找记录
            if(argc != 4) die("需要查找的名字或邮件来查找", conn);

            Database_find(conn, argv[3]);
            break;
            
        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list", conn);
    }

    Database_close(conn);

    return 0;
}