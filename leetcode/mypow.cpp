#include<iostream>
using namespace std;

//
double mypow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    if (n % 2 == 1) {
        return x * mypow(x, n - 1);
    } else {
        return mypow(mypow(x, n / 2), 2);
    }
}

double quickMul(double x, long long N) {
    if (N == 0) return 1.0;

    double y = quickMul(x, N / 2);
    return N % 2 == 0? y * y : y * y * x;
}

double myPow(double x, int n) {
    long long N = n;
    return N >= 0? quickMul(x, N) : 1.0 / quickMul(x, -N);
}

// 快速幂 迭代 ？？？
double quickMul(double x, long long N) {
    double ans = 1.0;
    // 贡献的初始值为x
    double x_contribute = x;
    // 在对N进行二进制拆分的同时计算答案
    while (N > 0) {
        if (N % 2 == 1) {
            // 如果N二进制表示的最低位为1，需要计入贡献
            ans *= x_contribute;
        }

        // 将贡献不断平方
        x_contribute *= x_contribute;
        // 舍弃N二进制表示的最低位
        N /= 2;
    }

    return ans;
}

double myPow(double x, int n) {
    long long N = n;

    return N >= 0? quickMul(x, N) : 1.0 / quickMul(x, -N);
}