#include <iostream>
#include <vector>
using namespace std;

// wrong
vector<int> res;
vector<int> ans;
vector<int> splitIntoFibonacci(string S) {
    dfs(S, 0);
    return ans;
}

void dfs(string& S, int index) {
    if (index > s.size()) return;
    if (index == S.size() && res.size() >= 3) {
        ans = res;
        return;
    }

    if (S[index] == '0') {
        if (res.size() < 2 || res[res.size() - 1] + res[res.size() - 2] == 0) {
            res.push_back(0);
            dfs(S, index + 1);
            res.pop_back();
        }

        return;
    }

    for (int i = 1; i <= S.size() - index; i++) {
        string s = S.substr(index, i);
        int num = stoi(s);
        if (res.size() >= 2 && res[res.size() - 1] + res[res.size() - 2] < num) return;

        if (res.size() < 2 || res[res.size() - 1] + res[res.size() - 2] == num) {
            res.push_back(num);
            dfs(S, index + i);
            res.pop_back();
        }
    }
}

// "123456579"
// [123, 456, 579]
index = 0 i = 3
index = 3 i = 3
index = 6 i = 3