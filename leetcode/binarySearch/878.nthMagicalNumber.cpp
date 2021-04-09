#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;
int nthMagicalNumber(int n, int a, int b) {
    long long i_a = 1, i_b = 1;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = min(i_a * a % mod, i_b * b % mod);
        if (res == i_a * a % mod) i_a++;
        if (res == i_b * b % mod) i_b++; 
    }
    return res;
}

// ¶þ·Ö
int GCD(int a, int b) {
    if (a < b) swap(a, b);
    while (b) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int LCM(int a, int b) {
    return a / GCD(a, b) * b;
}

int nthMagicalNumber(int n, int a, int b) {
    const int mod = 1e9 + 7;
    long left = 0, right = 1e15;
    while (left < right) {
        long mid = left + (right - left) / 2;
        if (mid / a + mid / b - mid / LCM(a, b) < n) {
            left = mid + 1;
        } else right = mid;
    }
    return (int)(left % mod);
}

// TODO: