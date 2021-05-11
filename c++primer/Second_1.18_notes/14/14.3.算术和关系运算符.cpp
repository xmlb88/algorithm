#include <iostream>
#include <vector>
using namespace std;

// 最有效的方式是使用复合赋值来定义算术运算符
Sales_data
operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;   // 把lhs的数据成员拷贝给sum
    sum += rhs; // 将rhs加到sum中
    return sum; // 最后函数返回sum的副本
}


// 相等运算符
// example
bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn() &&
           lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);
}


// 关系运算符
