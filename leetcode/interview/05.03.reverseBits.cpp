#include <iostream>
using namespace std;

// wrong
int reverseBits(int num) {
    vector<int> bit(32, 0);
    for (int i = 0; i < 32; i++) {
        if (num & (1 << i)) {
            bit[32 - i - 1] = 1;
        }
    }

    vector<int> count;
    for (int i = 0; i < 32; i++) {

    }


}

int reverseBits(int num) {
    if (~num == 0) return 32;

    uint32_t tmp = num;
    // unsigned tmp = num;
    int currentLength = 0;
    int previousLength = 0;
    int maxLength = 1;
    while (tmp != 0) {
        if ((tmp & 1)) {    // 当前位为1
            currentLength++;
        } else if ((tmp & 1) == 0) {    // 当前位为0
            // previousLength更新为0(下一位为0)或currentLength(下一位是1)
            previousLength = (tmp & 2) == 0 ? 0 : currentLength;
            currentLength = 0;
        }

        maxLength = max(maxLength, previousLength + currentLength + 1);
        tmp >>= 1;
    }
    return maxLength;
}

int reverseBits(int num) {
    if (~num == 0) return 32;

    int previous = 0;
    int current = 0;
    int length = 0;
    for (int i = 0; i < 32; i++) {
        if (num & 1) {
            current++;
        } else {
            previous = current;
            current = 0;
        }
        length = max(length, previous + current + 1);
        num >>= 1;
    }
    return length;
}