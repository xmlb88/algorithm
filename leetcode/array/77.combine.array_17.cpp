#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<vector<int>> combine(int n, int k) {
    vector<int> track;
    backtrace(track, 1, n, k);
    return res;
}

void backtrace(vector<int>& track, int start, int n, int k) {
    if (track.size() == k) {
        res.push_back(track);
        return;
    }

    for (int i = start; i <= n; i++) {
        // vector<int>::iterator it = find(track.begin(), track.end(), i);
        // if (it != track.end()) continue; // ²»ÐèÒª
        track.push_back(i);
        backtrace(track, i + 1, n, k);
        track.pop_back();
    }
}