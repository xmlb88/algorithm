#include <iostream>
#include <vector>
using namespace std;

bool isPerfectSquare(int num) {
    if (num == 1) return true;
    int left = 2, right = num / 2;
    while (left <= right) {
        long mid = left + right >> 1;
        long power = mid * mid;
        if (power== num) {
            return true;
        } else if (power > num) {
            right = mid - 1;
        } else if (power < num) {
            left = mid + 1;
        }
    }
    return false;
}

// Å£¶Ùµü´ú·¨
bool isPerfectSquare(int num) {
    if (num < 2) return true;
    long x = num / 2;
    while (x * x > num) {
        x = (x + num / x) / 2;
    }
    return x * x == num;
}