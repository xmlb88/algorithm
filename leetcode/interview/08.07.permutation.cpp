#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> res;
vector<string> permutation(string s) {
    string str;
    dfs(s, str);
    return res;
}

void dfs(string s, string str) {
    if (str.size() == s.size()) {
        res.push_back(str);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (str.find(s[i]) == string::npos) {
            str.push_back(s[i]);
            dfs(s, str);
            str.pop_back();
        }
    }
}