#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

// https://leetcode-cn.com/problems/word-ladder-ii/solution/dan-ci-jie-long-ii-by-leetcode-solution/
// TODO:
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    unordered_set<string> dict = {wordList.begin(), wordList.end()};
    if (dict.find(endWord) == dict.end()) {
        return res;
    }

    dict.erase(beginWord);
    unordered_map<string, int> steps = {{beginWord, 0}};
    unordered_map<string, set<string>> from = {{beginWord, {}}};
    int step = 0;
    bool found = false;
    queue<string> q;
    q.push(beginWord);
    int wordLen = beginWord.length();
    while (!q.empty()) {
        step++;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            const string currWord = q.front();
            string nextWord = currWord;
            q.pop();
            for (int j = 0; j < wordLen; ++j) {
                const char origin = nextWord[j];
                for (char c = 'a'; c <= 'z'; ++c) {
                    nextWord[j] = c;
                    if (steps[nextWord] == step) {
                        from[nextWord].insert(currWord);
                    }

                    if (dict.find(nextWord) == dict.end()) {
                        continue;
                    }

                    dict.erase(nextWord);
                    q.push(nextWord);
                    from[nextWord].insert(currWord);
                    steps[nextWord] = step;
                    if (nextWord == endWord) found = true;
                }
                nextWord[j] = origin;
            }
        }
        if (found) break;
    }

    if (found) {
        vector<string> path = {endWord};
        dfs(res, endWord, from, path);
    }
    return res;
}

void dfs(vector<vector<string>>& res, const string& node, unordered_map<string, set<string>>& from,
    vector<string>& path) {
    if (from[node].empty()) {
        res.push_back({path.rbegin(), path.rend()});
        return;
    }

    for (const string &parent : from[node]) {
        path.push_back(parent);
        dfs(res, parent, from, path);
        path.pop_back();
    }
}