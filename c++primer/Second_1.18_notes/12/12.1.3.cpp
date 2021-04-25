#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

void t_make_shared_ptr() {
    shared_ptr<double> p1;
    shared_ptr<int> p2(new int(42));    // p2指向一个值为42的int
    // shared_ptr<int> p3 = new int(42);   // 错误，必须使用直接初始化形式
    shared_ptr<int> p4 (new int(1024));
}

// 错误:隐式转换为shared_ptr<int>
// shared_ptr<int> clone(int p) {
//     return new int(p);
// }

shared_ptr<int> clone(int p) {
    // return shared_ptr<int>(new int(p));
    return make_shared<int>(p);
}

// 不能用get初始化另一个智能指针，或为智能指针赋值
shared_ptr<int> p(new int(42));
int *q = p.get();
{
    // 未定义，2个独立的shared_ptr指向相同的内存
    shared_ptr<int>(q);
}   // 程序块结束，q被销毁，它指向的内存被释放
int foo = *p;   // 未定义： p指向的内存已经被释放了

// 其他操作：
p = new int(1024);   // 错误：不能将一个指针赋予shared_ptr
p.reset(new int(1024)); // 正确，p指向一个新对象

int main() {
    return 0;
}