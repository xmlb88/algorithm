#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ±©Á¦
vector<int> shortestToChar(string s, char c) {
    vector<int> idx;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == c) idx.push_back(i);
    }

    vector<int> res;
    for (int i = 0; i < s.size(); ++i) {
        int dis = INT_MAX;
        for (int j = 0; j < idx.size(); ++j) {
            dis = min(dis, abs(i - idx[j]));
        }
        res.push_back(dis);
    }

    return res;
}

// 2´Î±éÀú
vector<int> shortestToChar(string s, char c) {
    vector<int> res;
    int last_idx = INT_MAX;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == c) last_idx = i;
        res.push_back(abs(last_idx - i));
    }

    last_idx = INT_MAX;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == c) last_idx = i;
        res[i] = min(res[i], abs(last_idx - i));
    }
    
    return res;
}