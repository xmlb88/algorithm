#include<iostream>
#include<string>
using namespace std;

bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }

    return i == s.size()? true : false;
}

bool isSubSequence(string s, string t) {
    int m = s.length(), n = t.length();
    vector<vector<int>> index(256);
    // �ȼ���t��ÿ���ַ����ֵ�λ��
    for (int i = 0; i < n; i++) {
        if ()
    }
}