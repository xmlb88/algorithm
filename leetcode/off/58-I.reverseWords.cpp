#include <iostream>
#include <string>
using namespace std;

// 中间2个空格 需要处理
string reverseWords(string s) {
    if (s.empty()) return s;
    string res;
    int i = s.size() - 1;
    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') i--;
        if (i < 0) break;
        int j = i;
        while (j >= 0 && s[j] != ' ') j--;

        res += s.substr(j + 1, i - j);
        res += ' ';
        i = j;
    }
    
    if (!res.empty()) res.pop_back();
    return res;
}

string trim(string s) {
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
    return s;
}
// ????????????????????

// "the sky is blue"
// i = 0, j = 3; reverse(0, 3)
// i = 4, j = 7; reverse(4, 7)
// i = 8, j = 10; reverse(8, 10);
// j = 11, s.end()