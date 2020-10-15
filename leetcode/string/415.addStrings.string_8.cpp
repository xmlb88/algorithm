#include <iostream>
#include <string>
#include <vector>
using namespace std;

string addStrings(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    int i = m - 1, j = n - 1;
    int add = 0;
    string res;
    while (i >= 0 || j >= 0 || add != 0) {
        int x = i >= 0? num1[i] - '0' : 0;
        int y = j >= 0? num2[j] - '0' : 0;
        int sum = x + y + add;
        res.push_back('0' + sum % 10);
        add = sum / 10;
        i--, j--;
    }
    reverse(res.begin(), res.end());
    return res;
}