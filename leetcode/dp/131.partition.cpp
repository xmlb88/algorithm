#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 回溯
vector<vector<string>> result;
vector<string> path; // 放已经回文的子串

void backtracking(const string& s, int startIndex) {
    // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
    if (startIndex >= s.size()) {
        result.push_back(path);
        return;
    }

    for (int i = startIndex; i < s.size(); i++) {
        if (isPalindrome(s, startIndex, i)) {   // 是回文子串
            // 获取[startIndex, i]在s中子串
            string str = s.substr(startIndex, i - startIndex + 1);
            path.push_back(str);
        } else {    // 不是回文，跳过
            continue;
        }

        backtracking(s, i + 1); // 寻找i + 1为起始位置的子串
        path.pop_back();    // 回溯过程，弹出本次已经填在的子串
    }
}

bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}



vector<vector<string>> partition(string s) {
    backtracking(s, 0);
    return result;
}

// review 2021年1月18日17:57:20
vector<vector<string>> res;
vector<string> path;
vector<vector<bool>> isPalind;
// bool isvalid(string& s, int start, int end) {
//     while (start < end) {
//         if (s[start] != s[end]) return false;
//         start++; end--;
//     }
//     return true;
// }

void dfs(string& s, int start) {
    if (start >= s.size()) {
        res.push_back(path);
        return;
    }

    for (int i = start; i < s.size(); i++) {
        if (isPalind[start][i]) {
            path.push_back(s.substr(start, i - start + 1));
            dfs(s, i + 1);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    int n = s.size();
    isPalind.resize(n, vector<bool> (n, false));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j]) {
                if (j - i + 1 <= 2) isPalind[i][j] = true;
                else isPalind[i][j] = isPalind[i + 1][j - 1];
            }
        }
    }

    dfs(s, 0);
    return res;
}