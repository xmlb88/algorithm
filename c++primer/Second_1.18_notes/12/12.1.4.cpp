#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

// 智能指针和异常

void f() {
    shared_ptr<int> sp(new int(42));    // 分配一个新对象
    // 这段代码抛出一个异常，且在f中未被捕获
}   // 在函数结束时shared_ptr自动释放内存

void f2() {
    int *ip = new int(42);  // 动态分配一个新对象
    // 这段代码抛出一个异常，且在f中未被捕获
    delete ip;  // 在退出之前释放内存
}

// example:
struct destination; // 表示我们正在连接什么
struct connection;  // 使用连接所需的信息
connection connect(destination*);   // 打开连接
void disconnect(connection);    // 关闭给定的连接
void f3(destination &d /* 其他参数 */ ) {
    // 获得一个连接，记住使用完后要关闭它
    connection c = connect(&d);
    // 使用连接
    // 如果我们在f退出前忘记调用disconnect,就无法关闭c了
}

// 先定义函数代替delete, 删除器(deleter)函数
void end_connection(connection *p) {
    disconnect(*p);
}

void f4(destination &d /* 其他参数 */ ) {
    connection c = connect(&d);
    shared_ptr<connection> p(&c, end_connection);
    // 使用连接，
    // 当f4退出时，即使由于异常而退出，connection会被正确关闭
}

// 416