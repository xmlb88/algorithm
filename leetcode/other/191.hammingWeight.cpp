#include <iostream>
#include <bitset>
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


// review 2021年3月22日09:13:28
int hammingWeight(uint32_t n) {
    return bitset<int>(n).count();
}

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= n - 1;
        ++count;
    }
    return count;
}

// 循环检查每个位的1
int hammingWeight(uint32_t n) {
    int count = 0;
    for (int i = 0; i < 32; ++i) {
        if (i & (1 << i)) {
            ++count;
        }
    }
    return count;
}