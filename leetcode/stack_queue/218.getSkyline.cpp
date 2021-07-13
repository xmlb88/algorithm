#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// [[0, 2, 3], [2, 5, 3]]
// [0, 3], [2, 0]   [2, 3], [5, 0]


// [[2, 9, 10], [3, 7, 15], [5, 12, 12]]
// [2, 10], [9, 0]  [3, 15], [7, 0]     [5, 12], [12, 0]
// [2, 10], [3, 15], []

vector<vector<int>> merge(vector<vector<int>>& skyline1, vector<vector<int>>& skyline2) {
    int h1 = 0, h2 = 0;
    int i = 0, j = 0;
    int n = skyline1.size(), m = skyline2.size();

    vector<vector<int>> res;
    while (i < n || j < m) {
        long x1 = i == n ? LONG_MAX : skyline1[i][0];
        long y1 = j == m ? LONG_MAX : skyline2[j][0];

        int x;
        if (x1 < y1) {
            x = x1;
            h1 = skyline1[i][1];
            ++i;
        } else if (x1 > y1) {
            x = y1;
            h2 = skyline2[j][1];
            ++j;
        } else {
            x = x1;
            h1 = skyline1[i][1];
            h2 = skyline2[j][1];
            ++i;
            ++j;
        }

        int h = max(h1, h2);
        if (res.empty() || res.back()[1] != h) {
            res.push_back({x, h});
        }
    }

    return res;
}

vector<vector<int>> divide(vector<vector<int>>& buildings, int left, int right) {
    if (left > right) return {};
    if (left == right) {
        auto& building = buildings[left];
        return {{building[0], building[2]}, {building[1], 0}};
    }

    int mid = left + (right - left) / 2;
    vector<vector<int>> skyline1 = divide(buildings, left, mid);
    vector<vector<int>> skyline2 = divide(buildings, mid + 1, right);
    return merge(skyline1, skyline2);
}

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    return divide(buildings, 0, buildings.size() - 1);
}


// …®√Ëœﬂ∑®
// https://leetcode-cn.com/problems/the-skyline-problem/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--45/

vector<vector<int>> 