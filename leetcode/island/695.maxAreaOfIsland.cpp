#include <iostream>
#include <vector>
#include <queue>
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



// review 2021Äê5ÔÂ28ÈÕ10:33:28
// DFS

int max_area = 0, cur_area = 0;

void dfs(vector<vector<int>>& grid, int x, int y) {
    int n = grid.size(), m = grid[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (grid[x][y] != 1) return;

    grid[x][y] = 2;
    ++cur_area;
    dfs(grid, x + 1, y);
    dfs(grid, x - 1, y);
    dfs(grid, x, y + 1);
    dfs(grid, x, y - 1);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                dfs(grid, i, j);
                max_area = max(max_area, cur_area);
                cur_area = 0;
            }
        }
    }
    return max_area;
}


// BFS

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;
    int max_area = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                int cur_area = 0;
                q.push(make_pair(i, j));
                while (!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 1) continue;
                    ++cur_area;
                    grid[x][y] = 2;
                    for (int k = 0; k < 4; ++k) {
                        q.push(make_pair(x + dx[k], y + dy[k]));
                    }
                }
                max_area = max(max_area, cur_area);
            }
        }
    }
    return max_area;
}


// https://leetcode-cn.com/problems/max-area-of-island/solution/dao-yu-de-zui-da-mian-ji-by-leetcode-solution/
//

// DFS

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

int dfs(vector<vector<int>>& gird, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()
        || grid[i][j] != 1) return 0;
    
    grid[i][j] = 0;
    int ans = 1;
    for (int index = 0; index < 4; ++index) {
        ans += dfs(grid, i + di[index], j + dj[index]);
    }
    return ans;
}

int maxAreaIsland(vector<vector<int>>& grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            ans = max(ans, dfs(grid, i, j));
        }
    }
    return ans;
}


// BFS