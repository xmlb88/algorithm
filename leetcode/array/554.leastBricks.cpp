#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> m;
    for (auto& rows : wall) {
        int n = rows.size();
        int sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            sum += rows[i];
            m[sum]++;
        }
    }

    int maxCnt = 0;
    for (auto c : m) {
        maxCnt = max(maxCnt, c.second);
    }
    return wall.size() - maxCnt;
}