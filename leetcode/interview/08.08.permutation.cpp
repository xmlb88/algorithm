#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> res;
vector<string> permutation(string s) {
    sort(s.begin(), s.end());
    string str;
    vector<bool> used(s.size(), false);
    dfs(s, str, used);
    return res;
}

void dfs(string& s, string& str, vector<bool>& used) {
    if (str.size() == s.size()) {
        res.push_back(str);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (!used[i]) {
            if (i > 0 && s[i - 1] == s[i] && used[i - 1]) continue;
            used[i] = true;
            str.push_back(nums[i]);
            dfs(s, str, used);
            used[i] = false;
            str.pop_back();
        }
    }
}