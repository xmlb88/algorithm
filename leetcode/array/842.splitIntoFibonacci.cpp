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
// index = 0 i = 3
// index = 3 i = 3
// index = 6 i = 3


vector<int> splitIntoFibonacci(string S) {
    vector<int> list;
    backtrack(list, S, S.length(), 0, 0, 0);
    return list;
}

bool backtrack(vector<int>& list, string S, int length, int index, long long sum, int prev) {
    if (index == length) {
        return list.size() >= 3;
    }

    long long curr = 0;
    for (int i = index; i < length; i++) {
        if (i > index && S[index] == '0') {
            break;
        }

        curr = curr * 10 + S[i] - '0';
        if (curr > INT_MAX) break;

        if (list.size() >= 2) {
            if (curr < sum) continue;
            else if (curr > sum) break;
        }
        list.push_back(curr);
        if (backtrack(list, S, length, i + 1, prev + curr, curr)) return true;
        list.pop_back();
    }

    return false;
}