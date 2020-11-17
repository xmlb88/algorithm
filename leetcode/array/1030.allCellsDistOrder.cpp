#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// sort
vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> points;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            points.push_back({i, j});
        }
    }

    sort(points.begin(), points.end(), [&](const vector<int>& a, const vector<int>& b)
                                        {return (abs(a[0] - r0) + abs(a[1] - c0)) < (abs(b[0] - r0) + abs(b[1] - c0));});
    return points;
}

// BFS
constexpr static int dx[4] = {-1, 0, 0, 1};
constexpr static int dy[4] = {0, -1, 1, 0};
vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(R, vector<bool> (C, false));
    vector<vector<int>> points;
    q.push(make_pair(r0, c0));
    points.push_back({r0, c0});
    visited[r0][c0] = true;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto kv = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int x = kv.first + dx[j], y = kv.second + dy[j];
                if (x < 0 || x >= R || y < 0 || y >= C) continue;
                if (visited[x][y]) continue;
                q.push(make_pair(x, y));
                points.push_back({x, y});
                visited[x][y] = true;
            }
        }
    }
    return points;
}

// 桶排序 线性
int dist(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    int maxDist = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
    vector<vector<vector<int>>> bucket(maxDist + 1);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int d = dist(i, j, r0, c0);
            bucket[d].push_back({i, j});
            // vector<int> tmp = {i, j};
            // bucket[d].push_back(move(tmp));
        }
    }

    vector<vector<int>> ret;
    for (int i = 0; i <= maxDist; i++) {
        for (auto &it : bucket[i]) {
            ret.push_back(it);
        }
    }

    return ret;
}

// 几何法 直接根据规律遍历
const int dr[4] = {1, 1, -1, -1};
const int dc[4] = {1, -1, -1, 1};
vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    int maxDist = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
    vector<vector<int>> ret;
    int row = r0, col = c0;
    ret.push_back({row, col});
    for (int dist = 0; dist <= maxDist; dist++) {
        row--;
        for (int i = 0; i < 4; i++) {
            whiel ((i % 2 == 0 && row != r0) || (i % 2 != 0 && col != c0)) {
                if (row >= 0 && row < R && col >= 0 && col < C) {
                    ret.push_back({row, col});
                }
                row += dr[i];
                col += dc[i];
            }
        }
    }
    return ret;
}