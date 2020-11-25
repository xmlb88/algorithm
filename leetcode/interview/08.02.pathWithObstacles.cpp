#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> path;
vector<vector<int>> res;
vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.size() == 0) return {};
    if (obstacleGrid[0][0] == 1) return {};
    path.push_back({0, 0});
    dfs(obstacleGrid, 0, 0);
    return res;
}

void dfs(vector<vector<int>>& obstacleGrid, int i, int j) {
    if (obstacleGrid[i][j] == 1) return;
    
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    if (i == n - 1 && j == m - 1) {
        res = path;
        return;
    }

    if (i + 1 < n && j < m) {
        path.push_back({i + 1, j});
        dfs(obstacleGrid, i + 1, j);
        path.pop_back();
    }

    if (i < n && j + 1 < m) {
        path.push_back({i, j + 1});
        dfs(obstacleGrid, i, j + 1);
        path.pop_back();
    }
}