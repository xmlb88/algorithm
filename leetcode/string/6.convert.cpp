#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) return s;
    vector<string> vec(numRows, "");

    int row = 0, next = 1;
    for (char c : s) {
        vec[row].push_back(c);
        if (row == 0) next = 1;
        else if (row == numRows - 1) next = -1;
        row += next;
    }

    string res;
    for (auto& rowStr : vec) {
        res += rowStr;
    }
    return res;
}

int main() {
    string s = "AB";
    cout << convert(s, 1) << endl;
}