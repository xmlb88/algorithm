#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int size;
vector<pair<int, int>> pos = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
void dfs(vector<vector<int>>& land, int x, int y, vector<vector<int>>& visited) {
    int n = land.size(), m = land[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (visited[x][y] || land[x][y] != 0) return;
    visited[x][y] = 1;
    ++size;

    for (auto [dx, dy] : pos) {
        dfs(land, x + dx, y + dy, visited);
    }
}

vector<int> pondSizes(vector<vector<int>>& land) {
    int n = land.size(), m = land[0].size();
    vector<vector<int>> visited(n, vector<int> (m, 0));
    size = 0;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (land[i][j] == 0 && !visited[i][j]) {
                dfs(land, i, j, visited);
                res.push_back(size);
                size = 0;
            }
        }
    }

    sort(res.begin(), res.end());
    return res;
}

vector<pair<int, int>> pos = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
vector<int> pondSizes(vector<vector<int>>& land) {
    int n = land.size(), m = land[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int> (m, 0));

    vector<int> res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (land[i][j] == 0 && !visited[i][j]) {
                q.push(make_pair(i, j));
                int size = 0;
                while (!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    if (land[x][y] != 0 || visited[x][y]) continue;
                    visited[x][y] = 1;
                    ++size;

                    for (auto [dx, dy] : pos) {
                        q.push(make_pair(x + dx, y + dy));
                    }
                }
                res.push_back(size);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}