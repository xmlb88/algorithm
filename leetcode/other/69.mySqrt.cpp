#include <iostream>
#include <cmath>
using namespace std;

// wrong :1 �õ� 0
// int mySqrt(int x) {
//     int left = 0, right = x;
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (mid * mid > x) {
//             right = mid - 1;
//         } else if (mid * mid < x) {
//             left = mid + 1;
//         } else if (mid * mid == x) {
//             return mid;
//         }
//     }

//     return right;
// }

// ����������㷨
// ����ָ��exp�Ͷ���ln��log����
int mySqrt(int x) {
    if (x == 0) return 0;
    int ans = exp(0.5 * log(x));
    return ((long long) (ans + 1) * (ans + 1) <= x) ? ans + 1 : ans;
}

// ����
int mySqrt(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    int left = 1, right = x / 2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid * mid > x) {
            right = mid - 1;
        } else if (mid * mid < x) {
            left = mid + 1;
        } else if (mid * mid == x) {
            return mid;
        }
    }

    return right;
}

// ţ�ٵ���
int mySqrt(int x) {
    if (x == 0) return 0;
    double last = 0;
    double res = 1;
    while (res != last) {
        last = res;
        res = (res + x / res) / 2;
    }
    return int(res);
}

int mySqrt(int x) {
    if (x == 0) return 0;
    double res = x;
    double last = x;
    while (true) {
        last = res;
        res = (res + x / res) / 2;
        if (abs(last - res) < 1e-6) {
            break;
        }
    }
    return int(res);
}