#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// TLE
int nthUglyNumber(int n, int a, int b, int c) {
    int ugly = 0;
    int p_a = 1, p_b = 1, p_c = 1;
    for (int i = 0; i < n; ++i) {
        ugly = min(min(p_a * a, p_b * b), p_c * c);
        if (ugly == p_a * a) ++p_a;
        if (ugly == p_b * b) ++p_b;
        if (ugly == p_c * c) ++p_c;
    }
    return ugly;
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

long long LCM(int a, int b) {
    return (long long)a * b / GCD(a, b);
}

int nums(int num, int a, int b, int c) {
    int m_a = num / a;
    int m_b = num / b;
    int m_c = num / c;
    int m_ab = num / LCM(a, b);
    int m_ac = num / LCM(a, c);
    int m_bc = num / LCM(b, c);
    int m_abc = num / LCM(LCM(a, b), c);
    return m_a + m_b + m_c - m_ab - m_ac - m_bc + m_abc;
}


int nthUglyNumber(int n, int a, int b, int c) {
    int left = min(min(a, b), c), right = left * n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums(mid, a, b, c) >= n) right = mid;
        else left = mid + 1;
    }
 
    return left - min(min(left % a, left % b), left % c);
}