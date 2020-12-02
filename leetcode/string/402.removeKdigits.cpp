#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

// kn
string removeKdigits(string num, int k) {
    if (num.size() == k) return "0";
    for(int i = 0; i < k; i++) {
        remove(num);
    }
    while (num.size() > 1 && num.front() == '0') {
        num.erase(num.begin());
    }
    return num;
}

void remove(string& num) {
    for (int i = 0; i < num.size(); i++) {
        if (i != num.size() - 1 && num[i] <= num[i + 1]) continue;
        num.erase(num.begin() + i);
        break;
    }
    return;
}

// µ¥µ÷Õ»
string removeKdigits(string num, int k) {
    if (num.size() == k) return "0";
    vector<char> stk;
    for (int i = 0; i < num.size(); i++) {
        while (!stk.empty() && k > 0 && stk.back() > num[i]) {
            stk.pop_back();
            k--;
        }
        stk.push_back(num[i]);
    }

    while (k) {
        stk.pop_back();
    }

    string res;
    int i = 0;
    while (i < stk.size() && stk[i] == '0') i++;
    while (i < stk.size()) res += stk[i++];
    return res.empty() ? "0" : res;
}