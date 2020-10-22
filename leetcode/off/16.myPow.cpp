#include <iostream>
#include <vector>
using namespace std;

// µÝ¹é¿ìËÙÃÝ
double myPow(double x, int n) {
    long N = n;
    return n >= 0? Pow(x, N) : 1 / Pow(x, -N);
}

double Pow(double x, long n) {
    if (n == 0) return 1.0;
    if (n == 1) return x;

    double y = myPow(x, n / 2);
    return n % 2 == 0? y * y : y * y * x;
}

// µü´ú
double myPow(double x, int n) {
    long long N = n;
    return N >= 0 ? quickMul(x, N) : 1 / quickMul(x, -N);
}

double quickMul(double x, long long N) {
    double res = 1.0;
    double x_contribute = x;
    while (N > 0) {
        if (N % 2 == 1) {
            res *= x_contribute;
        }
        x_contribute *= x_contribute;
        N /= 2;
    }
    return res;
}