#include <iostream>
#include <cmath>
using namespace std;

// wrong :1 得到 0
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

// 袖珍计算器算法
// 利用指数exp和对数ln（log）求
int mySqrt(int x) {
    if (x == 0) return 0;
    int ans = exp(0.5 * log(x));
    return ((long long) (ans + 1) * (ans + 1) <= x) ? ans + 1 : ans;
}

// 二分
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

// 牛顿迭代
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


// review 2021年3月19日16:22:18
int mySqrt(int x) {
    if (x < 2) return x;
    int left = 0, right = x / 2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long multiply = (long)mid * mid;
        if (multiply == x) return mid;
        else if (multiply > x) right = mid - 1;
        else if (multiply < x) left = mid + 1;
    }

    return right;
}

int mySqrt(int x) {
    if (x < 2) return x;

    int res = x / 2;
    while ((long)res * res > x) {
        res = (res + x / res) / 2;
    }
    return res;
}


// review 2021年6月7日11:43:41
// 8
int mySqrt(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    int left = 1, right = x / 2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long res = static_cast<long long>(mid) * mid;
        if (res == x) return mid;
        else if (res < x) left = mid + 1;
        else right = mid - 1;
    }
    return right;
}

int mySqrt(int x) {
    double last, res = 1.0;
    while (true) {
        last = res;
        res = (res + x / res) / 2;
        if (abs(last - res) < 1e-6) {
            break;
        }
    }
    return static_cast<int> (res);
}


// 数学 x ^ (1/2) = e ^ ((1/2)ln(x))
int mySqrt(int x) {
    if (x == 0) return 0;
    int res = exp(0.5 * log(x));
    return static_cast<long long>(res + 1) * (res + 1) <= x ? res + 1 : res;
}


// 二分
int mySqrt(int x) {
    if (x <= 1) return x;
    int left = 1, right = x / 2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long res = static_cast<long long> (mid) * mid;
        if (res == x) return mid;
        else if (res < x) left = mid + 1;
        else right = mid - 1;
    }
    return right;
}


// 牛顿迭代法
int mySqrt(int x) {
    if (x <= 1) return x;
    double last, res = x;
    while (true) {
        last = res;
        res = (res + x / res) / 2;
        if (abs(last - res) < 1e-6) break;
    }
    return static_cast<int>(res);
}