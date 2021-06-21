#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

vector<pair<int, int>> pos = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<int>>& ocean) {
    int n = heights.size(), m = heights[0].size();
    ocean[x][y] = 1;

    for (auto& f : pos) {
        int nx = x + f.first, ny = y + f.second;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (ocean[nx][ny]) continue;
        if (heights[nx][ny] >= heights[x][y]) dfs(heights, nx, ny, ocean);
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n = heights.size(), m = heights[0].size();
    vector<vector<int>> pacific(n, vector<int> (m, 0));
    vector<vector<int>> atlantic(n, vector<int> (m, 0));

    for (int i = 0; i < n; ++i) {
        dfs(heights, i, 0, pacific);
        dfs(heights, i, m - 1, atlantic);
    }

    for (int j = 0; j < m; ++j) {
        dfs(heights, 0, j, pacific);
        dfs(heights, n - 1, j, atlantic);
    }

    vector<vector<int>> res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
        }
    }
    return res;
}


vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n = heights.size(), m = heights[0].size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            
        }
    }
}