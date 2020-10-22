#include <iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n > 0) {
        if (n % 2 == 1) count++;
        n /= 2;
    }
    return count;
}

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
        if (n & 1) count++;
        n >>= 1;
    }
    return count;
}

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
        count++;
        n = n & (n - 1);
    }
    return count;
}

int hammingWeight(uint32_t n) {
    return ((bitset<32>)n).count();
}