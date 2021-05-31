#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int numberOfBoomerangs(vector<vector<int>>& points) {
    if (points.size() < 3) return 0;
    int res = 0;
    for (int i = 0; i < points.size(); ++i) {
        unordered_map<int, int> m;
        for (int j = 0; j < points.size(); ++j) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];
            int dis = dx * dx + dy * dy;
            m[dis]++;
        }

        for (auto& [_, val] : m) {
            res += val * (val - 1);
        }
    }
    return res;
}