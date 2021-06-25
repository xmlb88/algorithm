#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> memo;
bool dfs(string s, int index, unordered_set<string> dict) {
    if (index == s.size()) return true;
    if (memo[index] != -1) return memo[index];
    bool flag = false;
    for (int i = index + 1; i <= s.size(); ++i) {
        string sub = s.substr(index, i - index);
        if (dict.find(sub) != dict.end()) {
            flag = flag || dfs(s, i, dict);
        }
    }
    memo[index] = flag;
    return flag;
}

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    memo.resize(n, -1);
    return dfs(s, 0, dict);
}

int main() {
    string s = "a";
    vector<string> wordDict = {"a"};
    cout << wordBreak(s, wordDict) << endl;
}


bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<int> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}