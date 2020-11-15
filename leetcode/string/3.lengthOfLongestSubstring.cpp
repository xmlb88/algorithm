#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


// have a try // ac
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;
    int left = 0, right = 0;
    int length = 0;
    while (right < s.size()) {
        char c = s[right];
        right++;
        window[c]++;

        while (window[c] > 1) {
            char d = s[left];
            left++;
            if (window.count(d)) window[d]--;
        }

        length = max(length, right - left);
    }
    return length;
}

// follow up
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;
    int left = 0, right = 0;
    int res = 0;
    while (right < s.size()) {
        char c = s[right];
        right++;
        // ���д��������ݵ�һϵ�и���
        window[c]++;

        // �ж���ര���Ƿ�Ҫ����
        while (window[c] > 1) {
            char d = s[left];
            left++;
            window[d]--;
        }

        res = max(res, right - left);
    }
    return res;
}