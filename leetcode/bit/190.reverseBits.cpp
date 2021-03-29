#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

// 逐位颠倒
uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0;
    for (int i = 0; i < 32 && n > 0; ++i) {
        rev |= (n & 1) << (31 - i);
        n >>= 1;
    }
    return rev;
}

uint32_t reverseBits(uint32_t n) {
    int rev = 0;
    for (int i = 0; i < 32 && n > 0; ++i) {
        rev |= (n & 1) << (31 - i);
        n >>= 1;
    }
    return rev;
}

uint32_t reverseBits(uint32_t n) {
    long res = 0;
    for (int i = 0; i < 32; ++i) {
        res = res * 2 + n % 2;
        n /= 2;
    }
    return res;
}

// 1010 1010 1010 1010 1010 1010 1010 1010 : 0xaaaaaaaa
// 0101 0101 0101 0101 0101 0101 0101 0101 : 0x55555555
// 1100 1100                               : 0xcccccccc
// 0011 0011                               : 0x33333333
// 1111 0000                               : 0xf0f0f0f0
// 0000 1111                               : 0x0f0f0f0f
// 1111 1111 0000 0000 1111 1111 0000 0000 : 0xff00ff00
// 0000 0000 1111 1111 0000 0000 1111 1111 : 0x00ff00ff
// 1111 1111 1111 1111 0000 0000 0000 0000 : 0xffff0000
// 0000 0000 0000 0000 1111 1111 1111 1111 : 0x0000ffff

// 分治法
uint32_t reverseBits(uint32_t n) {
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = n >> 16 | n << 16;
    return n;
}

uint32_t reverseBits(uint32_t n) {
    n = n >> 16 | n << 16;
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}