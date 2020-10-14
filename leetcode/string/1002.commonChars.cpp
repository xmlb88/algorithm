#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// 数组记录每个字母次数
vector<string> commonChars(vector<string>& A) {
    int n = A.size();
    vector<int> min_count(26, INT_MAX);
    vector<int> count(26, 0);

    for (string word : A) {
        count.clear();
        count.resize(26, 0);
        // fill(count.begin(), count.end(), 0);
        for (char c : word) {
            count[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            min_count[i] = min(min_count[i], count[i]);
        }
    }

    vector<string> res;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < min_count[i]; j++) {
            string s(1, i + 'a');
            res.push_back(s);
        }
    }
    return res;
}