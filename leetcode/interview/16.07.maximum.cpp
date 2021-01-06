#include <iostream>
using namespace std;

int maximum(int a, int b) {
    return max(a, b);
}

// 溢出
int flip(int bit) {
    return 1 ^ bit;
}
int sign(int a) {
    return flip((a >> 31) & 1);
}
int maximum(int a, int b) {
    int k = sign(a - b);
    int q = flip(k);
    return a * k + b * q;
}

// 数学方法
int maximum(int a, int b) {
    long c = a;
    long d = b;
    int res = (int)((fabs(c - d) + c + d) / 2);
    return res;
}

// 
int maximum(int a, int b) {
    long x = (long)a - (long)b;
    int k = (int)(x >> 63);
    return (1 + k) * a - b * k;
}

int maximum(int a, int b) {
    long x = (long)a - (long)b;
    int k = ((int)(x >> 63) & 1);
    return (k ^ 1) * a + k * b;
}