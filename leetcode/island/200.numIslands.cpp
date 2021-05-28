#include <iostream>
#include <vector>
#include <queue>
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


// DFS
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void dfs(vector<vector<char>>& grid, int x, int y, vector<vector<int>>& visited) {
    int n = grid.size(), m = grid[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (grid[x][y] == '0') return;
    if (visited[x][y]) return;

    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        dfs(grid, x + dx[i], y + dy[i], visited);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && grid[i][j] == '1') {
                ++count;
                dfs(grid, i, j, visited);
            }
        }
    }
    return count;
}

// BFS

constexpr static int dx[4] = {0, 0, 1, -1};
constexpr static int dy[4] = {-1, 1, 0, 0};

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int res = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '1') {
                ++res;
                q.push(make_pair(i, j));
                while (!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != '1') continue;

                    grid[x][y] = '2';
                    for (int k = 0; k < 4; k++) {
                        q.push(make_pair(x + dx[k], y + dy[k]));
                    }
                }
            }
        }
    }
    return res;
}