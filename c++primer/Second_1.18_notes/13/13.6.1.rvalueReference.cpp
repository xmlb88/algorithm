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