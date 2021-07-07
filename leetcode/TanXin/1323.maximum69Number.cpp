#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maximum69Number(int num) {
    string s = to_string(num);
    for (auto& c : s) {
        if (c == '6') {
            c = '9';
            break;
        }
    }
    return stoi(s);
}