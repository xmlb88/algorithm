#include <iostream>
#include <string>
#include <vector>
using namespace std;

using F = int (int*, int); // 函数类型
using PF = int (*)(int*, int); // 指针类型

PF f1(int); // 正确
F f1(int); // 错误
F *f1(int); // 正确

// 直接声明
int (*f1(int))(int*, int);

// 尾置
auto f1(int) -> int (*)(int*, int);

int (int* p, int i) {
    return *p * i;
}

// 6_54:
int func(int, int);
typedef int (*pf)(int, int);
using f1 = int(int, int);
vector<int(*)(int, int)> vec = {func};
vector<decltype(func)*> vec;
vector<pf> vec;
vector<f1*> vec;
