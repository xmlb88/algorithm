#include <iostream>
using namespace std;

int insertBits(int N, int M, int i, int j) {
    for (int k = i; k <= j; k++) {
        if (N & (1 << k)) {
            N -= (1 << k);
        }
    }

    return N | (M << i);
}