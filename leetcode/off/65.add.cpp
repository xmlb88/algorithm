#include <iostream>
using namespace std;

// 位运算
int add(int a, int b) {
    while (b != 0) {
        int c = (unsigned int)(a & b) << 1; // 进位 = &运算 左移一位
        a ^= b; // 异或求非进位和
        b = c; // b = 进位
    }
    return a;
}