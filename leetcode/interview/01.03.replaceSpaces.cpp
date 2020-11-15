#include <iostream>
#include <string>
using namespace std;

string replaceSpaces(string s, int length) {
    string res;
    for (int i = 0; i < length; i++) {
        if (s[i] == ' ') res += "%20";
        else res += s[i];
    }
    return res;
}