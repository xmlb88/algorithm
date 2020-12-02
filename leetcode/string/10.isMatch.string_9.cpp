#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// bool isMatch(string s, string p) {
//     int i = 0, j = 0;
//     while (i < s.size() && j < p.size()) {
//         if (s[i] == p[j] || p[j] == '.') {
//             i++, j++;
//         } else return false;
//     }

//     return i == j && i == s.size() - 1 && j == p.size() - 1;
// }

// if (s[i] == p[j] || p[j] == '.') {
//     // ƥ��
//     if (j < p.size() - 1 && p[j + 1] == '*') {
//         // �� * ƥ���������ƥ��0�λ���
//     } else {
//         // �� * ƥ�����ƥ��1��
//         i++; j++;
//     } else {
//         // ��ƥ��
//         if (j < p.size() - 1 && p[j + 1] == '*') {
//             // �� * ƥ�����ֻ��ƥ��0��
//         } else {
//             // �� * ƥ�����ƥ���޷�������ȥ��
//             return false;
//         }
//     }
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

int main() {
    string s, p;
    cout << "input s: ";
    cin >> s;
    cout << "input p: ";
    cin >> p;
    if (isMatch(s, p)) {
        cout << "Match" << endl;
    } else {
        cout << "Not Match" << endl;
    }
}


// review
unordered_map<string, int> memo;
bool isMatch(string s, string p) {
    return dp(s, 0, p, 0);
}

bool dp(string s, int i, string p, int j) {
    int m = s.size(), n = p.size();
    if (j == n) {
        return i == m;
    }
    if (i == m) {
        if ((n - j) % 2 == 1) return false;

        for (int k = j + 1; k < n; k += 2) {
            if (p[k] != '*') return false;
        }

        return true;
    }

    string key = to_string(i) + "," + to_string(j);
    if (memo.count(key) > 0) return memo[key];

    bool res;
    if (s[i] == p[j] || p[j] == '.') {
        if (j < n - 1 && p[j + 1] == '*') {
            res = dp(s, i + 1, p, j) || dp(s, i, p, j + 2);
        } else {
            res = dp(s, i + 1, p, j + 1);
        }
    } else {
        if (j < n - 1 && p[j + 1] == '*') {
            res = dp(s, i, p, j + 2);
        } else {
            res = false;
        }
    }

    memo[key] = res;
    return res;
}