#pragma once
#include <iostream>
#include <vector>
using namespace std;

// TODO:
// important++
// 2021��1��29��10:03:55
// ����������� + ����[0, 10^6 - 1]
static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();

}