#include <iostream>
#include <vector>
using namespace std;

constexpr static int dx[4] = {1, 0, -1, 0};
constexpr static int dy[4] = {0, 1, 0, -1};

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                res++;
                dfs(grid, i, j);
            }
        }
    }
    return res;
}

void dfs(vector<vector<char>>& grid, int x, int y) {
    int n = grid.size(), m = grid[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '0') return;
    if (grid[x][y] == '2') return;

    grid[x][y] = '2';
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(grid, nx, ny);
    }
}