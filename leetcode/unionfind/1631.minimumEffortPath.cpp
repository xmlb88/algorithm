#pragma once
#include <iostream>
#include <vector>
using namespace std;

// TODO:
// important++
// 2021年1月29日10:03:55
// 广度优先搜索 + 二分[0, 10^6 - 1]
static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();

}