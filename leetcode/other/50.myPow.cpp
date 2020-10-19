#include <iostream>
#include <vector>
using namespace std;

double myPow(double x, int n) {
    long long N = n;
    if (N >= 0) return pow(x, N);
    else return 1.0 / pow(x, -N);
}

double pow(double x, long long n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    // if (n % 2 == 0) return pow(x, n / 2) * pow(x, n / 2);
    // else return pow(x, n / 2) * pow(x, n / 2) * x;
    double y = pow(x, n / 2);
    return n % 2 == 0 ? y * y : y * y * x;
}

// ����
double quickMul(double x, long long N) {
    double ans = 1.0;
    double x_contribute = x;

    while (N > 0) {
        if (N % 2 == 1) {
            ans *= x_contribute;
        }
        x_contribute *= x_contribute;
        N /= 2;
    }
    return ans;
}

double myPow(double x, int n) {
    long long N = n;
    return N >= 0? quickMul(x, N) : 1.0 / quickMul(x, -N);
}