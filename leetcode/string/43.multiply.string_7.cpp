#include <iostream>
#include <string>
using namespace std;

string multiply(string mul1, string mul2) {

}

string sumply(string mul1, string mul2) {
    int i = mul1.length() - 1, j = mul2.length() - 1;
    int mor = 0;
    string res;
    while (i >= 0 && j >= 0) {
        int sum1 = mul1[i] - '0';
        int sum2 = mul2[j] - '0';
        int sum = sum1 + sum2 + mor;
        res += to_string(sum / 10);
        mor = sum % 10;
        i--;
        j--;
    }
    if (i == -1) {
        while (j >= 0) {
            int sum2 = mul2[j] - '0';
            int sum = sum2 + mor;
            res += to_string(sum / 10);
            mor = sum % 10;
            j--;
        }
    }
    if (j == -1) {
        while (i >= 0) {
            int sum1 = mul1[i] - '0';
            int sum = sum1 + mor;
            res += to_string(sum / 10);
            mor = sum % 10;
            i--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

// TODO:
// FIXME: