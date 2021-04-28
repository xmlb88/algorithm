#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

// 初始化(必须使用直接初始化形式)
void t_unique_ptr_init() {
    unique_ptr<double> p1;
    unique_ptr<int> p2(new int(42));
}

// 不支持普通的拷贝或赋值操作
void t_unique_ptr() {
    unique_ptr<string> p1(new string("Stegosaurus"));
    unique_ptr<string> p2(p1);  // 错误，unique_ptr不支持拷贝
    unique_ptr<string> p3;
    p3 = p2;    // 错误，unique_ptr不支持赋值
}

unique_ptr<T> u1;
unique_ptr<T, D> u2;

unique_ptr<T, D> u(d);
u = nullptr;
u.release(); // u放弃对指针的控制权，返回指针，并将u置空
u.reset(q);
u.reset(nullptr);

unique_ptr<string> p2(p1.release());
unique_ptr<string> p3(new string("Trex"));
p2.reset(p3.release());

p2.release();   // 错误, p2不会释放内存，而且我们丢失了指针
auto p = p2.release();  // 正确，但我们必须记得delete(p)

// 传递unique_ptr参数和返回unique_ptr
// 不能拷贝unique_ptr的规则有一个例外：我们可以拷贝或赋值一个将要被销毁unique_ptr,

unique_ptr<int> clone(int p) {
    // 正确：从int*创建一个unique_ptr<int>
    return unique_ptr<int>(new int(p));
}

// 421