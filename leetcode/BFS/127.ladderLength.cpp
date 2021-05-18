#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

// BFS self 超时
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

    queue<string> que;
    // unordered_set<string> used;
    vector<bool> used(wordList.size(), false);
    que.push(beginWord);
    // used.insert(beginWord);
    // auto index = find(wordList.begin(), wordList.end(), beginWord);
    // if (index != wordList.end()) used[(int)index] = true;
    int res = 1;
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            string word = que.front();
            que.pop();

            // if (word == endWord) return res;
            // for (string backupWord : wordList) {
            //     int diff = 0;
            //     if (used.count(backupWord)) continue;
            //     for (int i = 0; i < word.length(); i++) {
            //         if (backupWord[i] != word[i]) diff++;
            //     }
            //     if (diff == 1) {
            //         que.push(backupWord);
            //         used.insert(backupWord);
            //     }
            // }

            if (word == endWord) return res;
            // used 改为bool数组
            for (int i = 0; i < wordList.size(); i++) {
                int diff = 0;
                if (used[i]) continue;
                for (int j = 0; j < word.length(); j++) {
                    if (wordList[i][j] != word[j]) diff++;
                }
                if (diff == 1) {
                    que.push(wordList[i]);
                    // used.insert(wordList[i]);
                    used[i] = true;
                }
            }
        }
        res++;
    }
    return 0;
}

// 优化
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

    unordered_set<string> visited;
    queue<string> que;
    que.push(beginWord);
    visited.insert(beginWord);
    int count = 0;
    while (!que.empty()) {
        int size = que.size();
        count++;
        for (int i = 0; i < size; i++) {
            string start = que.front();
            que.pop();

            for (string s : wordList) {
                if (visited.count(s)) continue;
                if (!canConvert(start, s)) continue;

                if (s == endWord) return count + 1;
                visited.insert(s);
                que.push(s);
            }
        }
    }
    return 0;
}

bool canConvert(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    int count = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) count++;
        if (count > 1) return false;
    }
    return count == 1;
}

// 双向BFS
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(),wordList.end());
    if(!dict.count(endWord)){
        return 0;
    }      
    unordered_set<string> q1{beginWord};
    unordered_set<string> q2{endWord};
    int l=beginWord.size();
    int step=0;
    while(!q1.empty()&&!q2.empty()){
        step++;
        if(q1.size()>q2.size()){
            swap(q1,q2);
        }
        unordered_set<string> q;
        for(string w:q1){
            for(int i=0;i<l;i++){
                char c=w[i];
                for(int j='a';j<='z';j++){
                    w[i]=j;
                    if(q2.count(w)){
                        return step+1;
                    }
                    if(!dict.count(w)){
                        continue;
                    }
                    dict.erase(w);
                    q.insert(w);
                }
                w[i]=c;
            }
        }
        swap(q,q1);
    }
    return 0;
}


// review 2021年5月18日15:15:16
// BFS
bool canTransfer(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    int count = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) ++count;
        if (count > 1) return false;
    }
    return count == 1;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
    int n = wordList.size();
    vector<int> visited(n, 0);
    queue<string> q;
    q.push(beginWord);
    int res = 1;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            string word = q.front();
            q.pop();
            if (word == endWord) return res;

            for (int j = 0; j < n; ++j) {
                if (visited[j]) continue;

                if (canTransfer(word, wordList[j])) {
                    q.push(wordList[j]);
                    visited[j] = 1;
                }
            }
        }
        ++res;
    }
    return 0;
}


// 优化？
bool canTransfer(string s1, string s2) {
    if (s1.size() != s2.size()) return fasle;
    int count = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) ++count;
        if (count > 1) return false;
    }
    return count == 1;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
    unordered_set<string> used;
    queue<string> q;
    q.push(beginWord);
    used.insert(beginWord);
    int res = 0;
    while (!q.empty()) {
        ++res;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            string word = q.front();
            q.pop();
            if (word == endWord) return res;
            for (const string& s : wordList) {
                if (used.find(s) != used.end()) continue;
                if (canTransfer(word, s)) {
                    q.push(s);
                    used.insert(s);
                }
            }
        }
    }
    return 0;
}

// TODO: