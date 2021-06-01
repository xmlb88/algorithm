#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// 1 2 3 4
vector<int> findSubstring(string s, vector<string>& words) {
    int n = words.size(), m = words[0].size(), len = n * m;
    vector<int> res;
    if (s.size() < len) return res;
    unordered_map<string, int> word_count;
    for (string& word : words) {
        word_count[word]++;
    }

    for (int i = 0; i <= s.size() - len; ++i) {
        unordered_map<string, int> match;
        int start = i, match_count = 0;
        while (match_count < n) {
            string sub = s.substr(start, m);
            if (word_count.find(sub) == word_count.end()) {
                break;
            }
            ++match[sub];
            if (match[sub] > word_count[sub]) break;
            ++match_count;
            start = start + m;
        }
        if (match_count == n) res.push_back(i);
    }
    return res;
}

// »¬¶¯´°¿Ú
vector<int> findSubstring(string s, vector<string> words) {
    int n = words.size(), m = words[0].size(), len = n * m;
    vector<int> res;
    if (s.size() < n * m) return res;

    unordered_map<string, int> word_count;
    unordered_map<string, int> window;
    for (string& word : words) {
        word_count[word]++;
    }
    for (int i = 0; i < m; ++i) {
        int left = i, right = i;
        window.clear();
        while (right < s.size()) {
            string sub = s.substr(right, m);
            right += m;
            if (word_count.find(sub) != word_count.end()) {
                window[sub]++;

                while (window[sub] > word_count[sub]) {
                    string left_sub = s.substr(left, m);
                    window[left_sub]--;
                    left += m;
                }
                if (right - left == len) res.push_back(left);
            } else {
                left = right;
                window.clear();
            }
        }
    }
    return res;
}


int main() {
    vector<string> words = {"fooo","barr","wing","ding","wing"};
    string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<int> res = findSubstring(s, words);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
}