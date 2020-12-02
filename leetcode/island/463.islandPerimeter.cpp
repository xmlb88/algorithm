#include <iostream>
#include <vector>
using namespace std;

// TODO:
// DFS
constexpr static int dx[4] = {0, 1, 0, -1};
constexpr static int dy[4] = {1, 0, -1, 0};

int islandPerimeter(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) return dfs(i, j, grid);
        }
    }
    return 0;
}

int dfs(int x, int y, vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
        return 1;
    }

    if (grid[x][y] == 2) return 0;

    grid[x][y] = 2;
    int res = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        res += dfs(nx, ny, grid);
    }
    return res;
}

// ÆÕÍ¨µü´ú
constexpr static int dx[4] = {0, 1, 0, -1};
constexpr static int dy[4] = {1, 0, -1, 0};

int islandPerimeter(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == 0) {
                        res += 1;
                    }
                }
            }
        }
    }
    return res;
}