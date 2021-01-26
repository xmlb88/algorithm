#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ±©Á¦
bool isValid(const vector<int>& a, const vector<int>& b) {
    return (a[0] == b[0] && a[1] == b[1]) || (a[0] == b[1] && a[1] == b[0]);
}

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int n = dominoes.size();
    if (n == 0) return 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isValid(dominoes[i], dominoes[j])) res++;
        }
    }
    return res;
}

// 
int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int n = dominoes.size();
    if (n == 0) return 0;
    unordered_map<int, int> m;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int first = dominoes[i][0], second = dominoes[i][1];
        if (first < second) swap(first, second);
        int hashNum = first * 10 + second;
        res += m[hashNum];
        m[hashNum]++;
    }
    return res;
}