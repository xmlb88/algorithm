#include <iostream>
#include <vector>
using namespace std;

int base = 1337;

int myPow(int a, int b) {
    a %= base;
    int res = 1;
    for (int i = 0; i < b; i++) {
        res *= a;
    }
    res %= base;
    return res;
}

int base = 1337;
// ÓÅ»¯myPow
int myPow(int a, int b) {
    if (b == 0) return 1;
    a %= base;
    if (b % 2 != 0) {
        return (a * myPow(a, b - 1)) % base;
    } else {
        int sub = myPow(a, b / 2);
        return (sub * sub) % base;
    }
}

int superPow(int a, vector<int>& b) {
    if (b.empty()) return 1;
    int last = b.back();
    b.pop_back();
    
    int part1 = myPow(a, last);
    int part2 = myPow(superPow(a, b), 10);

    return (part1 * part2) % base;
}