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

    // ����¼��¼״̬(i, j)�������ص�������
    string key = to_string(i) + "," + to_string(j);
    if (memo.count(key)) return memo[key];

    bool res;
    if (s[i] == p[j] || p[j] == '.') {
        // ƥ��
        if (j < p.size() - 1 && p[j + 1] == '*') {
            // 1.1 ͨ���ƥ��0�λ���
            res = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
        } else {
            // 1.2 ����ƥ��1��
            res = dp(s, i + 1, p, j + 1);
        }
    } else {
        // ��ƥ��
        if (j < p.size() - 1 && p[j + 1] == '*') {
            // 2.1 ͨ���ƥ��0��
            res = dp(s, i, p, j + 2);
        } else {
            // 2.2 �޷�����ƥ��
            res = false;
        }
    }

    // ����ǰ������뱸��¼
    memo[key] = res;
    return res;
}

bool isMatch(string s, string p) {
    return dp(s, 0, p, 0);
}