#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// TODO:
// no ac
string reverseWords(string s) {
    stringstream ss(s);
    string temp;
    vector<string> res;
    while (getline(ss, temp, ' ')) {
        res.push_back(temp);
    }

    string result;
    for (int i = res.size() - 1; i >= 0; i--) {
        if (i == 0) result += res[i];
        else result = result + res[i] + " ";
    }

    return result;
}

string reverseWords(string s) {
    // 反转整个字符串
    reverse(s.begin(), s.end());

    int n = s.size();
    int idx = 0;
    for (int )
}