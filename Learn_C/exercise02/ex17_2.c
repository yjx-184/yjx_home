#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// 单个地址的记录
struct Address {
    int id;                         // 地址编号
    int set;                        // 标记是否被设置（1 表示已设置，0 表示未设置）
    char *name;                     // 指向存储名字的指针（动态分配内存）
    char *email;                    // 指向存储电子邮件地址的指针（动态分配内存）
};

// 数据库，包含多个地址记录
struct Database {
    int max_data;                   // 每条记录中 name 和 email 字段的最大长度
    int max_rows;                   // 数据库中最大记录数
    struct Address *rows;           // 指向存储所有地址记录的指针（动态分配内存）
};

// 数据库连接，用于管理文件和数据库
struct Connection {
    FILE *file;                     // 指向数据库文件的指针
    struct Database *db;            // 指向数据库的指针
};

// 函数声明
void die(struct Connection *conn, const char *message);
void Address_print(struct Address *addr);
void Database_load(struct Connection *conn);
struct Connection *Database_open(const char *filename, char mode, int max_data, int max_rows);
void Database_close(struct Connection *conn);
void Database_write(struct Connection *conn);
void Database_create(struct Connection *conn);
void Database_set(struct Connection *conn, int id, const char *name, const char *email);
void Database_get(struct Connection *conn, int id);
void Database_delete(struct Connection *conn, int id);
void Database_list(struct Connection *conn);
void Database_find(struct Connection *conn, const char *keyword);

// 错误处理函数，打印错误信息并退出程序
void die(struct Connection *conn, const char *message)
{
    if(errno) {
        perror(message);            // 如果有错误号，打印系统错误信息
    } else {                        // 否则打印自定义错误信息
        printf("ERROR: %s\n", message);
    }
    Database_close(conn);
    exit(1);                        // 退出程序
}

// 打印地址记录
void Address_print(struct Address *addr)
{
    printf("%d %s %s\n",            // 打印地址记录的 ID、名字和电子邮件
            addr->id, addr->name, addr->email);
}

// 从文件加载数据库内容
void Database_load(struct Connection *conn)
{
    // 读取 max_data 和 max_rows
    fread(&conn->db->max_data, sizeof(int), 1, conn->file);
    fread(&conn->db->max_rows, sizeof(int), 1, conn->file);
    // 动态分配 rows 数组
    conn->db->rows = malloc(conn->db->max_rows * sizeof(struct Address));
    for (int i = 0; i < conn->db->max_rows; i++) {
        struct Address *addr = &conn->db->rows[i];
        fread(&addr->id, sizeof(int), 1, conn->file);       // 读取 id
        fread(&addr->set, sizeof(int), 1, conn->file);      // 读取 set 标志
        addr->name = malloc(conn->db->max_data);            // 分配 name 内存
        addr->email = malloc(conn->db->max_data);           // 分配 email 内存
        fread(addr->name, conn->db->max_data, 1, conn->file); // 读取 name
        fread(addr->email, conn->db->max_data, 1, conn->file); // 读取 email
    }
}

// 打开数据库连接
struct Connection *Database_open(const char *filename, char mode, int max_data, int max_rows)
{
    // 分配内存给连接对象
    struct Connection *conn = malloc(sizeof(struct Connection));    
    if(!conn) die(conn, "分配内存给连接对象失败");

    // 分配内存给数据库对象
    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die(conn,"分配内存给数据库对象失败");

    // 初始化数据库的 max_data 和 max_rows
    conn->db->max_data = max_data;
    conn->db->max_rows = max_rows;
    // 分配内存给存储所有地址记录的数组
    conn->db->rows = malloc(sizeof(struct Address) * max_rows);
    if(!conn->db->rows) die(conn, "分配内存给存储所有地址的数据库对象失败");

    // 初始化每条记录
    for (int i = 0; i < max_rows; i++) {
        conn->db->rows[i].id = i;                          // 设置 id
        conn->db->rows[i].set = 0;                         // 初始化 set 标志为 0
        conn->db->rows[i].name = malloc(max_data);         // 分配 name 内存
        conn->db->rows[i].email = malloc(max_data);        // 分配 email 内存
        if (!conn->db->rows[i].name || !conn->db->rows[i].email) die(conn, "分配内存给名字或邮件失败");
    }

    // 根据模式打开文件
    if(mode == 'c') {
        conn->file = fopen(filename, "w");  // 以写模式创建文件
    } else {
        conn->file = fopen(filename, "r+"); // 以读写模式打开文件
        if(conn->file) {
            Database_load(conn);            // 加载数据库内容
        }
    }

    if(!conn->file) die(conn, "打开文件失败");      // 打开文件失败则退出

    return conn;                            // 返回连接对象
}

// 关闭数据库连接并释放内存
void Database_close(struct Connection *conn)
{
    if(conn) {
        if(conn->file) fclose(conn->file);  // 关闭文件
        if(conn->db) {
            for (int i = 0; i < conn->db->max_rows; i++) {
                free(conn->db->rows[i].name);  // 释放每条记录的 name 内存
                free(conn->db->rows[i].email); // 释放每条记录的 email 内存
            }
            free(conn->db->rows);  // 释放记录数组内存
            free(conn->db);        // 释放数据库结构体内存
        }
        free(conn);  // 释放连接结构体内存
    }
}

// 将数据库内容写入文件
void Database_write(struct Connection *conn)
{
    if (!conn->file) die(conn, "文件指针无效");  // 检查文件指针是否有效
    rewind(conn->file);  // 将文件指针重置到文件开头

    // 写入 max_data 和 max_rows
    if (fwrite(&conn->db->max_data, sizeof(int), 1, conn->file) != 1)
        die(conn, "写入 max_data 失败");
    if (fwrite(&conn->db->max_rows, sizeof(int), 1, conn->file) != 1)
        die(conn, "写入 max_rows 失败");

    // 写入每条记录的内容
    for (int i = 0; i < conn->db->max_rows; i++) {
        struct Address *addr = &conn->db->rows[i];
        if (fwrite(&addr->id, sizeof(int), 1, conn->file) != 1)
            die(conn, "写入 id 失败");
        if (fwrite(&addr->set, sizeof(int), 1, conn->file) != 1)
            die(conn, "写入 set 失败");
        if (fwrite(addr->name, conn->db->max_data, 1, conn->file) != 1)
            die(conn, "写入 name 失败");
        if (fwrite(addr->email, conn->db->max_data, 1, conn->file) != 1)
            die(conn, "写入 email 失败");
    }
    fflush(conn->file);  // 强制将缓冲区内容写入文件
}

// 创建空的数据库
void Database_create(struct Connection *conn)
{
    for (int i = 0; i < conn->db->max_rows; i++) {
        conn->db->rows[i].id = i;                          // 设置 id
        conn->db->rows[i].set = 0;                         // 初始化 set 标志为 0
        conn->db->rows[i].name = malloc(conn->db->max_data);  // 分配 name 内存
        conn->db->rows[i].email = malloc(conn->db->max_data); // 分配 email 内存
        if (!conn->db->rows[i].name || !conn->db->rows[i].email) die(conn,"内存分配失败");
        memset(conn->db->rows[i].name, 0, conn->db->max_data);  // 初始化 name 为空字符串
        memset(conn->db->rows[i].email, 0, conn->db->max_data); // 初始化 email 为空字符串
    }
}

// 设置地址记录
void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
    struct Address *addr = &conn->db->rows[id];     // 获取指定 id 的地址记录
    if(addr->set) die(conn,"记录已经设置");              // 如果记录已设置，报错

    addr->set = 1;                                  // 标记记录为已设置
    char *res = strncpy(addr->name, name, conn->db->max_data);  // 复制名字到记录中
    if(!res) die(conn, "复制名字失败");
    res = strncpy(addr->email, email, conn->db->max_data);      // 复制电子邮件到记录中
    if(!res) die(conn, "复制邮件失败");
}

// 获取并打印地址记录
void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];     // 获取指定 id 的地址记录

    if(addr->set) {
        Address_print(addr);                        // 如果记录已设置，打印信息
    } else {
        die(conn,"ID未设置");                            // 否则报错
    }
}

// 删除地址记录
void Database_delete(struct Connection *conn, int id)
{
    if (id < 0 || id >= conn->db->max_rows) die(conn,"ID 超出范围");  // 检查 id 是否有效

    struct Address *addr = &conn->db->rows[id];
    addr->set = 0;  // 标记为未设置
    free(addr->name);  // 释放 name 的内存
    free(addr->email); // 释放 email 的内存
    addr->name = malloc(conn->db->max_data);  // 重新分配 name 内存
    addr->email = malloc(conn->db->max_data); // 重新分配 email 内存
    if (!addr->name || !addr->email) die(conn,"内存分配失败");
    memset(addr->name, 0, conn->db->max_data);  // 初始化 name 为空字符串
    memset(addr->email, 0, conn->db->max_data); // 初始化 email 为空字符串
}

// 列出所有已设置的地址记录
void Database_list(struct Connection *conn)
{
    for (int i = 0; i < conn->db->max_rows; i++) {
        struct Address *cur = &conn->db->rows[i];  // 获取当前记录
        if(cur->set) {
            Address_print(cur);  // 如果记录已设置，打印信息
        }
    }
}

// 查找功能
void Database_find(struct Connection *conn, const char *keyword)
{
    for (int i = 0; i < conn->db->max_rows; i++) {
        struct Address *addr = &conn->db->rows[i];
        if(addr->set && (
            strstr(addr->name, keyword) ||
            strstr(addr->email, keyword)
        )) {
            Address_print(addr);
        }
    }
}

// 主函数
int main(int argc, char *argv[])
{
    // 如果参数不足，调用 die 函数
    if(argc < 3) die(NULL, "USAGE: ex17 <dbfile> <action> [action params]");

    char *filename = argv[1];               // 数据库文件名
    char action = argv[2][0];               // 获取操作类型
    struct Connection *conn = NULL;
    int max_data = 0, max_rows = 0;
    
    if (action == 'c') {
        if (argc != 5) die(conn, "创建需要 max_rows 和 max_data");
        max_rows = atoi(argv[3]);           // 解析 max_rows
        max_data = atoi(argv[4]);           // 解析 max_data
        conn = Database_open(filename, action, max_data, max_rows);
    } else {
        // 其他操作直接打开数据库，参数设为 0（实际会被覆盖）
        conn = Database_open(filename, action, 0, 0);
    }
    
    // 获取 id 时，根据操作类型调整参数索引
    int id = 0;
    if (action == 's' || action == 'g' || action == 'd') {
        if (argc < 4) die(conn, "需要 id");
        id = atoi(argv[3]);  // 解析 id
    }

    // 检查 id 是否超出范围
    if (id >= conn->db->max_rows) die(conn, "超出范围");

    // 根据操作类型执行相应操作
    switch(action) {
        case 'c':  // 创建数据库
            Database_create(conn);
            Database_write(conn);
            break;

        case 'g':  // 获取记录
            if(argc != 4) die(conn, "需要 id 才能获取");
            Database_get(conn, id);
            break;

        case 's':  // 设置记录
            if(argc != 6) die(conn, "需要 id、name 和 email 来设置");
            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd':  // 删除记录
            if(argc != 4) die(conn, "删除需要 id");
            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':  // 列出所有记录
            Database_list(conn);
            break;

        case 'f':
            if(argc != 4) die(conn, "需要搜索关键字");
            Database_find(conn, argv[3]);
            break;

        default:
            die(conn, "无效操作: c=创建, g=获取, s=设置, d=删除, l=列表");
    }

    Database_close(conn);  // 关闭数据库连接

    return 0;
}