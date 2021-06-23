#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
    string res = "";
    int i = a.size() - 1, j = b.size() - 1;
    int add = 0;
    while (i >= 0 || j >= 0 || add) {
        int sum = add;
        if (i >= 0) {
            sum += a[i] - '0';
            --i;
        }

        if (j >= 0) {
            sum += b[j] - '0';
            --j;
        }

        add = sum / 2;
        res.push_back((sum % 2) + '0');
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string a = "11", b = "1";
    cout << addBinary(a, b) << endl;
}