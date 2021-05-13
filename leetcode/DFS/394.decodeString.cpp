#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string decodeString(string s) {
    stack<char> st_c;
    stack<int> st_i;
    
    int num = 0;
    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else {
            if (c == '[') {
                st_i.push(num);
                num = 0;
                st_c.push(c);
            } else if (c == ']') {
                string s;
                while (st_c.top() != '[') {
                    s.push_back(st_c.top());
                    st_c.pop();
                }
                st_c.pop();
                int count = st_i.top();
                st_i.pop();
                string s_repeat;
                while (count--) {
                    s_repeat += s;
                }
                while (!s_repeat.empty()) {
                    st_c.push(s_repeat.back());
                    s_repeat.pop_back();
                }
            } else {
                st_c.push(c);
            }
        }
    }

    string res;
    while (!st_c.empty()) {
        res.push_back(st_c.top());
        st_c.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string s = "2[abc]3[cd]ef";
    cout << decodeString(s) << endl;
} 


// ¸¨ÖúÕ»
string getDigits(string& s, size_t &ptr) {
    string ret = "";
    while (isdigit(s[ptr])) {
        ret.push_back(s[ptr++]);
    }
    return ret;
}

string getString(vector<string>& v) {
    string ret;
    for (const auto& s : v) {
        ret += s;
    }
    return ret;
}

string decodeString(string s) {
    vector<string> stk;
    size_t ptr = 0;

    while (ptr < s.size()) {
        char cur = s[ptr];
        if (isdigit(cur)) {
            string digits = getDigits(s, ptr);
            stk.push_back(digits);
        } else if (isalpha(cur) || cur == '[') {
            stk.push_back(string(1, s[ptr++]));
        } else {
            ++ptr;
            vector<string> sub;
            while (stk.back() != "[") {
                sub.push_back(stk.back());
                stk.pop_back();
            }
            reverse(sub.begin(), sub.end());
            stk.pop_back();
            int repTime = stoi(stk.back());
            stk.pop_back();
            string t, o = getString(sub);
            while (repTime--) t += o;
            stk.push_back(t);
        }
    }

    return getString(stk);
}

// µÝ¹é TODO:
string src;
size_t ptr;

int getDigits() {
    int ret = 0;
    while (ptr < src.size() && isdigit(src[ptr])) {
        ret = ret * 10 + src[ptr++] - '0';
    }
    return ret;
}

string getString() {
    if (ptr == src.size() || src[ptr] == ']') {
        return "";
    }

    char cur = src[ptr];
    int repTime = 1;
    string ret;
    if (isdigit(cur)) {
        retTime = getDigits();
        ++ptr;
        string str = getString();
        ++ptr;
        while (repTime--) ret += str;
    } else if (isalpha(cur)) {
        ret = string(1, src[ptr++]);
    }

    return ret + getString();
}

string decodeString(string s) {
    src = s;
    ptr = 0;
    return getString();
}