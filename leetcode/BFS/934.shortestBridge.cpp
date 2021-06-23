#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TLE
queue<pair<int, int>> q;
vector<pair<int, int>> pos{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
void dfs(vector<vector<int>>& grid, int x, int y) {
    int n = grid.size(), m = grid[0].size();
    q.push(make_pair(x, y));
    grid[x][y] = 2;
    for (auto [dx, dy] : pos) {
        if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < m && grid[x + dx][y + dy] == 1) {
            dfs(grid, x + dx, y + dy);
        }
    }
}

int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                found = true;
                dfs(grid, i, j);
                break;
            }
        }
        if (found) break;
    }

    int bridge = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (auto [dx, dy] : pos) {
                if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < m) {
                    if (grid[x + dx][y + dy] == 1) return bridge;
                    else if (grid[x + dx][y + dy] == 0) q.push(make_pair(x + dx, y + dy));
                }
            }
        }
        ++bridge;
    }
    return -1;
}

int main() {
    // vector<vector<int>> grid = {
    //     {0, 1}, {1, 0}
    // };

    vector<vector<int>> grid = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
    cout << shortestBridge(grid) << endl;
}

// TODO: