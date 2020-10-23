#include <iostream>
#include <string>
using namespace std;

// vector<vector<int>> memo;
// bool isMatch(string s, string p) {
//     int n = s.size(), m = p.size();
//     memo.resize(n, vector<int>(m, -1));
// }

// bool match(string& s, string& p, int i, int j) {
//     int n = s.size(), m = p.size();
//     if (j == m) return i == n;

//     if (i == n) {
//         if ((m - j) % 2 == 1) return false;

//         for (int k = j; k < m; k += 2) {
//             if (p[k] != '*') return false;
//         }
//         return true;
//     }

//     if (memo)


// }


unordered_map<string, int> memo;

bool dp(string& s, int i, string& p, int j) {
    // base case
    int m = s.size(), n = p.size();
    if (j == n) {
        return i == m;
    }
    if (i == m) {
        if ((n - j) % 2 == 1) {
            return false;
        }
        for (; j + 1 < n; j+= 2) {
            if (p[j + 1] != '*') {
                return false;
            }
        }
        return true;
    }

    // 备忘录记录状态(i, j)，消除重叠子问题
    string key = to_string(i) + "," + to_string(j);
    if (memo.count(key)) return memo[key];

    bool res;
    if (s[i] == p[j] || p[j] == '.') {
        // 匹配
        if (j < p.size() - 1 && p[j + 1] == '*') {
            // 1.1 通配符匹配0次或多次
            res = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
        } else {
            // 1.2 常规匹配1次
            res = dp(s, i + 1, p, j + 1);
        }
    } else {
        // 不匹配
        if (j < p.size() - 1 && p[j + 1] == '*') {
            // 2.1 通配符匹配0次
            res = dp(s, i, p, j + 2);
        } else {
            // 2.2 无法继续匹配
            res = false;
        }
    }

    // 将当前结果记入备忘录
    memo[key] = res;
    return res;
}

bool isMatch(string s, string p) {
    return dp(s, 0, p, 0);
}