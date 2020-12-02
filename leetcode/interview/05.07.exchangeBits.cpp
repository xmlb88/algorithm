#include <iostream>
#include <bitset>
using namespace std;

int exchangeBits(int num) {
    bitset<32> b(num);
    for (int i = 0; i < 31; i += 2) {
        if (b.test(i) != b.test(i + 1)) {
            b[i] = ~b[i];
            b[i + 1] = ~b[i + 1];
        }
    }

    // return static_cast<int>(b.to_ulong());
    // return (int)b.to_ulong()
    return b.to_ulong();
}

int exchangeBits(int num) {
    int odd = num & 0b01010101010101010101010101010101;
    int even = num & 0b10101010101010101010101010101010;
    return (odd << 1) | (even >> 1);
}