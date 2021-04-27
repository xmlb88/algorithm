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


void reset_with_unique() {
    if (!p.unique()) {
        p.reset(new string(*p));    // 我们不是唯一用户，分配新的拷贝
    }
    *p += newVal;   //现在是唯一用户，可以改变对象的值
}


// 不要混用普通指针和智能指针

void process(shared_ptr<int> ptr) { // 值传递，实参拷贝到ptr中，拷贝递增引用计数
    // 使用ptr
}   // ptr离开作用域，被销毁

// 在process运行过程中，引用计数值至少为2，当process结束时，ptr的引用计数会递减，但不会变为0，
// 当局部变量ptr被销毁时，ptr指向的内存不会释放

// 正确方法
shared_ptr<int> p(new int(42));
process(p);
int i = *p; // 正确，引用计数值为1

// 不能传递给process一个内置指针，但可以传递给他一个临时的shared_ptr
// shared_ptr是用一个内置指针构造的，但是，这样做很可能会导致错误
int *x(new int(1024)); // x是普通指针，
process(x); //错误，不能讲int*转换为一个shared_ptr<int>
process(shared_ptr<int>(x));    //合法的，但内存会被释放
int j = *x; // 未定义，x是一个空悬指针




int main() {
    return 0;
}

// practice_12.10:
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
/* 正确。shared_ptr<int>(p) 会创建一个临时的智能指
针，这个智能指针与 p 引用同一个对象，此时引用计数为 2。当表达式结束时，临时的智能指针被销毁，此时引用计数为 1 */

// practice_12.11:
process(shared_ptr<int>(p.get()));