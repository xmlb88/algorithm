#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ³¬Ê±
string res = "";
vector<string> result;
string reorganizeString(string S) {
    vector<bool> used(S.size(), false);
    dfs(S, used);
    return result.empty() ? "" : result[0];
}

bool dfs(string& s, vector<bool>& used) {
    if (res.size() == s.size()) {
        result.push_back(res);
        return true;
    }

    for (int i = 0; i < s.size(); i++) {
        if (!used[i] && s[i] != res.back()) {
            res.push_back(s[i]);
            used[i] = true;
            bool f = dfs(s, used);
            if (f) return true;
            res.pop_back();
            used[i] = false;
        }
    }
}

// ´ó¶¥¶Ñ + Ì°ÐÄ
string reorganizeString(string S) {
    if (S.length() < 2) return S;
    vector<int> counts(26, 0);
    int maxCount = 0;
    int length = S.length();
    for (int i = 0; i < length; i++) {
        char c = S[i];
        counts[c - 'a']++;
        maxCount = max(maxCount, counts[c - 'a']);
    }

    if (maxCount > (length + 1) / 2) return "";
    auto cmp = [&] (const char& letter1, const char& letter2) {
        return counts[letter1 - 'a'] < counts[letter2 - 'a'];
    };

    priority_queue<char, vector<char>, decltype(cmp) > queue{cmp};
    for (char c = 'a'; c <= 'z'; c++) {
        if (counts[c - 'a'] > 0) {
            queue.push(c);
        }
    }

    string sb = "";
    while (queue.size() > 1) {
        char letter1 = queue.top(); queue.pop();
        char letter2 = queue.top(); queue.pop();
        sb += letter1;
        sb += letter2;
        int index1 = letter1 - 'a', index2 = letter2 - 'a';
        counts[index1]--;
        counts[index2]--;
        if (counts[index1] > 0) queue.push(letter1);
        if (counts[index2] > 0) queue.push(letter2);
    }

    if (queue.size() > 0) {
        sb += queue.top();
    }
    return sb;
}