#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//DFS
constexpr static int dx[4] = {-1, 0, 0, 1};
constexpr static int dy[4] = {0, -1, 1, 0};
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {

}

int dfs(vector<vector<int>>& matrix, int x, int y, ) {
    if (matrix[x][y] == 0) return 0;

}


// BFS
constexpr static int dx[4] = {-1, 0, 0, 1};
constexpr static int dy[4] = {0, -1, 1, 0};
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                visited[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }

    int distance = 1;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto kv = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = kv.first + dx[i], y = kv.second + dy[i];
                if (x < 0 || x >= n) continue;
                if (y < 0 || y >= m) continue;
                if (visited[x][y]) continue;
                matrix[x][y] = distance;
                visited[x][y] = true;
                q.push(make_pair(x, y));
            }
        }
        distance++;
    }

    return matrix;
}