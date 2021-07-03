#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> m;
    for (char c : s) {
        m[c]++;
    }

    vector<pair<char, int>> vec;
    for (auto cnt : m) {
        vec.push_back(cnt);
    }

    sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    });

    string res = "";
    for (auto& [c, n] : vec) {
        res += string(n, c);
    }
    return res;
}

// TODO:Õ∞≈≈–Ú

