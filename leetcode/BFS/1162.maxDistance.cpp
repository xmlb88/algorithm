#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
int findNearestIsland(vector<vector<int>>& grid, int x, int y) {
    int dis = 0, n = grid.size();
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int> (n, 0));
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    while (!q.empty()) {
        int size = q.size();
        for (int s = 0; s < size; ++s) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = 1;
                if (grid[nx][ny]) return dis + 1;
                else q.push(make_pair(nx, ny));
            }
        }
        ++dis;
    }
    return -1;
}

int maxDistance(vector<vector<int>>& grid) {
    int max_dis = -1, n = grid.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!grid[i][j]) {
                max_dis = max(max_dis, findNearestIsland(grid, i, j));
            }
        }
    }
    return max_dis;
}

// violence
// int maxDistance(vector<vector<int>>& grid) {
//     int max_dis = 0;
//     int n = grid.size();
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             if (grid[i][j] == 0) {
//                 int dis = INT_MAX;
//                 for (int p = 0; p < n; ++p) {
//                     for (int q = 0; q < n; ++q) {
//                         if (grid[p][q] == 1) {
//                             dis = min(dis, abs(i - p) + abs(j - q));
//                         }
//                     }
//                 }
//                 max_dis = max(max_dis, dis);
//             }
//         }
//     }
//     return max_dis == INT_MAX ? -1 : max_dis;
// }

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
int maxDistance(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int n = grid.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j]) q.push(make_pair(i, j));
        }
    }

    if (q.size() == 0 || q.size() == n * n) return -1;

    int max_dis = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int s = 0; s < size; ++s) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (grid[nx][ny]) continue;
                grid[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
        ++max_dis;
    }
    return --max_dis;
}