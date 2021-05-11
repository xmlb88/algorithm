#include <iostream>
#include <vector>
#include <string>
using namespace std;

int i = 42;
int &r = i; // 正确：r引用i
int &&rr = i;   // 错误：不能将一个右值引用绑定到一个左值上
int &r2 = i * 42;   // 错误：i * 42是一个右值
const int &r3 = i * 42; // 正确，将一个const的引用绑定到一个右值上
int &&rr2 = i * 42; // 正确：将rr2绑定到乘法结果上


int &&rr1 = 42;     // 正确：字面常量是右值
int &&rr2 = rr1;    // 错误：表达式rr1是左值
#include <utility> // move
int &&rr3 = std::move(rr1); // ok
// 使用move直接用std::move

// 474

struct X {
    int i;  // 内置类型可以移动
    std::string s;  // string定义了自己的移动操作
};

struct hasX {
    X mem;  // x有合成的移动操作
};

X x, x2 = std::move(x); // 使用合成的移动构造函数
hasX hx, hx2 = std::move(hx);


class Foo {
public:
    Foo() = default;
    Foo(const Foo&);
};

Foo x;
Foo y(x);
Foo z(std::move(x));

class HasPtr {
public:
    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {p.ps = 0;}
    HasPtr& operator=(HasPtr rhs) {
        swap(*this, rhs);
        return *this;
    }
};
