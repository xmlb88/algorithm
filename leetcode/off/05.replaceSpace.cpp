#include <iostream>
#include <string>
using namespace std;

string replaceSpace(string s) {
    string res;
    for (char c : s) {
        if (c == ' ') {
            res += "%20";
        }
        else res += c;
    }
    return res;
}