#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findNthDigit(int n) {
    string s = "0";
    for (int i = 1; i <= 220000; i++) {
        s += to_string(i);
    }
    return s[n] - '0';
}
// TODO: