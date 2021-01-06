#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> largeGroupPositions(string s) {
    int start = 0, end = 0;
    int n = s.size();
    vector<vector<int>> res;
    if (n == 0) return res;
    while (end < n) {
        while (end < n && s[end] == s[start]) end++;
        if (end - start >= 3) {
            res.push_back({start, end - 1});
        }
        start = end;
    }

    return res;
}