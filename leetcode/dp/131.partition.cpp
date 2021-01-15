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

// bool isPalindrome(const string& s, int start, int end) {
//     while (start < end) {
//         if (s[start] != s[end]) {
//             return false;
//         }
//         start++;
//         end--;
//     }
//     return true;
// }



vector<vector<string>> partition(string s) {
    backtracking(s, 0);
    return result;
}
