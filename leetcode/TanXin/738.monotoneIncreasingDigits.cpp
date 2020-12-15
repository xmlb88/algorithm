#include <iostream>
#include <string>
using namespace std;

int monotoneIncreasingDigits(int N) {
    string strN = to_string(N);
    for (int i = strN.length() - 2; i >= 0; i--) {
        if (strN[i] > strN[i + 1]) {
            for (int j = i + 1; j < strN.length(); j++) {
                strN[j] = '9';
            }
            strN[i] = strN[i] - 1;
        }
    }

    return stoi(strN);
}

//674 599

//654 599

//647 599