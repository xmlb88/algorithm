#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    int left = 0, right = 0;
    int valid = 0;
    // ��¼��С�����Ӵ�����ʼ�����ͳ���
    int start = 0, len = INT_MAX;
    while (right < s.size()) {
        // c�ǽ����봰�ڵ��ַ�
        char c = s[right];
        // ���ƴ���
        right++;
        // ���д��������ݵ�һϵ�и���
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) valid++;
        }

        // �ж���ര���Ƿ�Ҫ����
        while (valid == need.size()) {
            // �����������С�����Ӵ�
            if (right - left < len) {
                start = left;
                len = right - left;
            }
            // d�ǽ��Ƴ����ַ�
            char d = s[left];
            // ���ƴ���
            left++;
            // ���д����ڵ�һϵ�и���
            if (need.count(d)) {
                if (window[d] == need[d]) valid--;
                window[d]--;
            }
        }
    }
    return len == INT_MAX? "" : s.substr(start, len);
}


// review 2020��10��27��09:47:28
string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    int left = 0, right = 0;
    int valid = 0;
    int start = 0, length = INT_MAX;
    for (char c : t) {
        need[c]++;
    }
    while (right < s.size()) {
        char c = s[right];
        right++;
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) {
                valid++;
            }
        }

        while (valid == need.size()) {
            if (right - left < length) {
                start = left;
                length = right - left;
            }

            char d = s[left];
            left++;
            if (need.count(d)) {
                if (window[d] == need[d]) valid--;
                window[d]--;
            }
        }
    }
    return length == INT_MAX? "" : s.substr(start, length);
}

string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    int left = 0, right = 0;
    int valid = 0;
    int start = 0, length = INT_MAX;
    for (char c : t) need[c]++;
    while (right < s.size()) {
        char c = s[right];
        right++;
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) valid++;
        }

        while (valid == need.size()) {
            if (right - left < length) {
                start = left;
                length = right - left;
            }

            char d = s[left];
            left++;
            if (need.count(d)) {
                if (window[d] == need[d]) valid--;
                window[d]--;
            }
        }
    }
    return length == INT_MAX? "" : s.substr(start, length);
}