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


// review 2021��3��16��17:57:27
// �ݹ������
// �����������ݣ��Ը������д���

double pow(double x, long long n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    double y = pow(x, n / 2);
    return (n & 1) ? y * y * x : y * y;
}

double myPow(double x, int n) {
    long long N = n;
    return n >= 0 ? pow(x, N) : 1.0 / pow(x, -N);
}

// ����������
double myPow(double x, long long N) {
    double ans = 1.0;
    double x_contribute = x;
    while (N > 0) {
        if (N & 1) {
            ans *= x_contribute;
        }
        x_contribute *= x_contribute;
        N >>= 1;
    }
    return ans;
}

// x = 5.0, N = 9
// ans = 1.0, x_contribute = x = 5;
// ans = 5^1 x_contribute = x^1 * x^1 = x^2 N = 4
// ans = 5^1 x_contribute = x^4 N = 2
// ans = 5^1 x_contribute = x^8 N = 1

// ���������ݣ���N���ж����Ʋ�֣�������Ϊ1�ĵط������
double pow(double x, long long N) {
    double ans = 1.0;
    double x_contribute = x;
    while (N > 0) {
        if (N & 1) {
            ans *= x_contribute;
        }
        x_contribute *= x_contribute;
        N >>= 1;
    }
    return ans;
}

double myPow(double x, int n) {
    long long N = n;
    return N >= 0 ? pow(x, N) : 1.0 / pow(x, -N);
}