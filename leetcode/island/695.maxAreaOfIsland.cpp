#include <iostream>
#include <vector>
using namespace std;

constexpr static int dx[4] = {0, 1, 0, -1};
constexpr static int dy[4] = {1, 0, -1, 0};

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) maxArea = max(maxArea, dfs(grid, i, j));
        }
    }
    return maxArea;
}

int dfs(vector<vector<int>>& grid, int x, int y) {
    int n = grid.size(), m = grid[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || grid[x][y] == 2) {
        return 0;
    }

    grid[x][y] = 2;
    int res = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        res += dfs(grid, nx, ny);
    }
    return res;
}
