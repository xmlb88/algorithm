#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 前置递增/递减运算符
class StrBlobPtr {
public:
    // 递增和递减运算符
    StrBlobPtr& operator++();   // 前置运算符
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int); // 后置运算符
    StrBlobPtr operator--(int);
};

StrBolbPtr& StrBolbPtr::operator++() {
    // 如果curr已经指向了容器的尾后位置，则无法递增它
    check(curr, "increment past end of StrBlobPtr");
    ++curr; // 将curr在当前状态下向前移动一个元素
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--() {
    // 如果curr是0，则继续递减它将产生一个无效下标
    --curr; // 将curr在当前状态下向后移动一个元素
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

// 后置运算符
// 在递增对象之前需要首先记录对象的状态
StrBlobPtr StrBlobPtr::operator++(int) {
    // 此处无须检查有效性，调用前置递增运算时才需要检查
    StrBlobPtr ret = *this; // 记录当前的值
    ++*this;    // 向前移动一个元素，前置++需要检查递增的有效性
    return ret; // 返回之前记录的状态
}

StrBlobPtr StrBlobPtr::operator--(int) {
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

// 显示地调用后置运算符
StrBlobPtr p(a1);
p.operator++(0);    // 调用后置版本的operator++
p.operator++(); // 调用前置版本的operator++