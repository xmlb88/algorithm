#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// 暴力hash
int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
    unordered_map<string, vector<int>> m;
    int n = wordsDict.size();
    for (int i = 0; i < n; ++i) {
        m[wordsDict[i]].push_back(i);
    }

    int res = INT_MAX;
    for (auto& i : m[word1]) {
        for (auto& j : m[word2]) {
            res = min(res, abs(i - j));
        }
    }
    return res;
}

// 优化 保存最近出现的索引
int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
    int i = -1, j = -1;
    int n = wordsDict.size();
    int res = INT_MAX;
    for (int k = 0; k < n; ++k) {
        if (wordsDict[k] == word1) {
            i = k;
        } else if (wordsDict[k] == word2) {
            j = k;
        }

        if (i != -1 && j != -1) {
            res = min(res, abs(i - j));
        }
    }
    return res;
}