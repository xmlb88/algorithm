#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 类值版本HasPtr
class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) {}
    // 对ps指向的string，每个HasPtr对象都有自己的拷贝
    HasPtr(const HasPtr &p):
        ps(new std::string(*p.ps)), i(p.i) {}
    HasPtr& operator=(const HasPtr &);
    ~HasPtr() { delete ps; }
private:
    std::string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    auto newp = new string(*rhs.ps);    // 拷贝底层string
    delete ps;  // 释放旧内存
    ps = newp;  // 从右侧运算对象拷贝数据到本对象
    i = rhs.i;
    return *this;   // 返回本对象
}

inline
void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);   // 交换指针，而不是string数据
    swap(lhs.i, rhs.i);     // 交换int成员
}

// inline
// void swap(HasPtr &lhs, HasPtr &rhs) {
//     using std::swap;
//     swap(lhs.ps, rhs.ps);
//     swap(lhs.i, rhs.i);
// }

// 使用swap进行拷贝并交换完成赋值操作
// rhs按值传递，意味着HasPtr的拷贝构造函数
// 将右侧运算对象中的string拷贝到rhs
HasPtr& HasPtr::operator=(HasPtr rhs) {
    // 交换左侧运算对象和局部变量rhs的内容
    swap(*this, rhs);   // rhs现在指向本对象曾经使用的内存
    return *this;   // rhs被销毁，从而delete了rhs中的指针
}