#include <iostream>
#include <vector>
using namespace std;

bool isOneBitCharacter(vector<int>& bits) {
    int n = bits.size();
    int i = 0;
    while (i < n) {
        if (i == n - 2) return true;

        if (bits[i] == 1) {
            i += 2;
            continue;
        }

        if (bits[i] == 0) {
            i++;
            continue;
        }
    }
    return false;
}

bool isOneBitCharacter(vector<int>& bits) {
    int i = 0;
    while (i < bits.size() - 1) {
        i += bits[i] + 1;
    }
    return i == bits.size() - 1;
}