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

// ������ ���� ������
double quickMul(double x, long long N) {
    double ans = 1.0;
    // ���׵ĳ�ʼֵΪx
    double x_contribute = x;
    // �ڶ�N���ж����Ʋ�ֵ�ͬʱ�����
    while (N > 0) {
        if (N % 2 == 1) {
            // ���N�����Ʊ�ʾ�����λΪ1����Ҫ���빱��
            ans *= x_contribute;
        }

        // �����ײ���ƽ��
        x_contribute *= x_contribute;
        // ����N�����Ʊ�ʾ�����λ
        N /= 2;
    }

    return ans;
}

double myPow(double x, int n) {
    long long N = n;

    return N >= 0? quickMul(x, N) : 1.0 / quickMul(x, -N);
}