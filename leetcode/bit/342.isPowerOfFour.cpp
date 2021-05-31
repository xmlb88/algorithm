#include <iostream>
using namespace std;

bool isPowerOfFour(int n) {
    if (n == 0) return false;
    while (n % 4 == 0) {
        n /= 4;
    }
    return n == 1;
}

// 1 0001  4 0100  16 1 0000
bool isPowerOfFour(int n) {
    if (n == 0) return false;
    while (n % 4 == 0) {
        n /= 4;
    }
    return n == 1;
}

// bit
bool isPowerOfFour(int n) {
    if (n == 0) return false;
    return n > 0 && (n & (n - 1)) == 0 && (n & 0b10101010101010101010101010101010) == 0;
}

bool isPowerOfFour(int n) {
    if (n == 0) return false;
    return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
}

// mod

bool isPowerOfFour(int n) {
    if (n == 0) return false;
    return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
}