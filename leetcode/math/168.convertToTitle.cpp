#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// TODO:
string convertToTitle(int columnNumber) {
    string res = "";
    while (columnNumber) {
        --columnNumber;
        res.push_back(columnNumber % 26 + 'A');
        columnNumber /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cout << convertToTitle(702) << endl;
}


// 100 ... 3 ... 22