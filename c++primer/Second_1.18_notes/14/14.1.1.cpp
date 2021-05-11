#include <iostream>
#include <vector>
using namespace std;

// 非成员运算符函数的等价调用
data1 + data2;  // 普通的表达式
operator=(data1, data2);    // 等价的函数调用

data1 += data2; // 基于调用的表达式
data1.opoerator+=(data2);   // 对成员运算符函数的等价调用

// 不应该重载的运算符：逗号，取地址，逻辑与和逻辑或运算符

// 赋值(=), 下标([]), 调用(()), 和成员访问箭头(->)运算符必须是成员
// 复合赋值运算符一般来说应该是成员，但并非必须，
// 改变对象状态的运算符或者与给定类型密切相关的运算符，如递增、递减、和
//      解引用运算符，通常应该是成员
// 具有对称性的运算符可能转换任意一端的运算对象，例如算术，相等性，关系和位
//      运算符等，因此它们通常应该是普通的非成员函数

// example
string s = "world";
string t = s + "!"; // 正确：能把一个const char*加到一个string对象中
string u = "hi" + s;// 如果+是string的成员，则产生错误

// 等价
s.operator+("!")
"hi".operator+(s);  // const char*, 这是一种内置类型，没有成员函数
