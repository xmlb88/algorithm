#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;
v = {"a", "an", "the"};

// 同样把这个运算符添加到StrVec类中
class StrVec {
public:
    StrVec &operaotr=(std::initializer_list<std::string>);
}

StrVec &StrVec::operator=(initializer_list<string> il) {
    // alloc_n_copy分配内存空间并从给定范围内拷贝元素
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    retur *this;
}

// 复合赋值运算符

// 作为成员的二元运算符：左侧运算对象绑定到隐式的this指针
// 假定两个对象表示的是同一本书
Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}