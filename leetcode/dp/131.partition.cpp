#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ����
vector<vector<string>> result;
vector<string> path; // ���Ѿ����ĵ��Ӵ�

void backtracking(const string& s, int startIndex) {
    // �����ʼλ���Ѿ�����s�Ĵ�С��˵���Ѿ��ҵ���һ��ָ����
    if (startIndex >= s.size()) {
        result.push_back(path);
        return;
    }

    for (int i = startIndex; i < s.size(); i++) {
        if (isPalindrome(s, startIndex, i)) {   // �ǻ����Ӵ�
            // ��ȡ[startIndex, i]��s���Ӵ�
            string str = s.substr(startIndex, i - startIndex + 1);
            path.push_back(str);
        } else {    // ���ǻ��ģ�����
            continue;
        }

        backtracking(s, i + 1); // Ѱ��i + 1Ϊ��ʼλ�õ��Ӵ�
        path.pop_back();    // ���ݹ��̣����������Ѿ����ڵ��Ӵ�
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

// review 2021��1��18��17:57:20
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


// review 2021��3��8��
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<bool>> isPalind;
vector<string> vec;
vector<vector<string>> res;

vector<vector<string>> partition(string s) {
    isPalindRome(s);
    backtrack(s, 0);
    return res;
}

void backtrack(string& s, int index) {
    if (index == s.size()) {
        res.push_back(vec);
        return;
    }

    for (int i = index; i < s.size(); ++i) {
        if (isPalind[index][i]) {
            vec.push_back(s.substr(index, i - index + 1));
            backtrack(s, i + 1);
            vec.pop_back();
        }
    }
}

void isPalindRome(string s) {
    int n = s.size();
    isPalind.resize(n, vector<bool> (n, false));

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (j - i + 1 <= 2 && s[i] == s[j]) isPalind[i][j] = true;
            else if (s[i] == s[j]) isPalind[i][j] = isPalind[i + 1][j - 1];
        }
    }
}



// review 2021��3��9��
vector<vector<bool>> isPalind;
vector<string> vec;
vector<vector<string>> res;
vector<vector<string>> partition(string s) {
    // ����isPalind����
    int n = s.size();
    isPalind.resize(n, vector<bool> (n, false));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (s[i] == s[j]) {
                if (j - i + 1 <= 2) isPalind[i][j] = true;
                else isPalind[i][j] = isPalind[i + 1][j - 1];
            }
        }
    }

    // ����
    backtrack(s, 0);
    return res;
}

void backtrack(string& s, int index) {
    if (index == s.size()) {
        res.push_back(vec);
        return;
    }

    for (int i = index; i < s.size(); ++i) {
        if (isPalind[index][i]) {
            vec.push_back(s.substr(index, i - index + 1));
            backtrack(s, i + 1);
            vec.pop_back();
        }
    }
}

// ������չ������isPalind����
vector<vector<bool>> isPalind;
vector<string> vec;
vector<vector<string>> res;

vector<vector<string>> partition(string s) {
    int n = s.size();
    // ������չ��
    isPalind.resize(n, vector<bool> (n, false));
    for (int i = 0; i < n; i++) {
        isPalindRome(s, i, i);
        isPalindRome(s, i, i + 1);
    }

    backtrack(s, 0);
    return res;
}

void isPalindRome(string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        isPalind[left][right] = true;
        --left; ++right;
    }
}

void backtrack(string& s, int index) {
    if (index == s.size()) {
        res.push_back(vec);
        return;
    }

    for (int i = index; i < s.size(); ++i) {
        if (isPalind[index][i]) {
            vec.push_back(s.substr(index, i - index + 1));
            backtrack(s, i + 1);
            vec.pop_back();
        }
    }
}