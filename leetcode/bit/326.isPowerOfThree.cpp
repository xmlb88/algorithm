#include <iostream>
using namespace std;

bool isPowerOfThree(int n) {
    if (n == 0) return false;
    while (n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}


// normal
bool isPowerOfThree(int n) {
    if (n == 0) return false;
    while (n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}

// 1 0001 3 0011 9 1001 27 1 1011