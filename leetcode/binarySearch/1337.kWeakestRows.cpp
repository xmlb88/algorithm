#include <iostream>
#include <vector>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    vector<pair<int, int>> power;
    for (int i = 0; i < n; ++i) {
        int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
        power.emplace_back(sum, i);
    }

    sort(power.begin(), power.end());
    vector<int> res;
    for (int i = 0; i < k; ++i) {
        res.push_back(power[i].second);
    }
    return res;
}
