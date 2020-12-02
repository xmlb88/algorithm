#include <iostream>
#include <string>
using namespace std;

// ±©Á¦·¨
int countDigitOne(int n) {
    int countOne = 0;
    for (int i = 1; i <= n; i++) {
        string str = to_string(i);
        countOne += count(str.begin(), str.end(), '1');
    }
    return countOne;
}


//TODO: