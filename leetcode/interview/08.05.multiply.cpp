#include <iostream>
using namespace std;

int multiply(int A, int B) {
    int res = 0;

    if (A < B) {
        int temp = A;
        A = B;
        B = temp;
    }

    for (int i = 0; i < B; i++) {
        res += A;
    }

    return res;
}

int multiply(int A, int B) {
    if (B == 1) return A;

    int res = 0;
    int pre = multiply(A, B / 2);
    if (B & 1) {
        res = pre + pre + A;
    } else {
        res = pre + pre;
    }

    return res;
}