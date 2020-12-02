#include <iostream>
#include <vector>
using namespace std;

// DFS
int oldColor;
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    oldColor = image[sr][sc];
    if (oldColor == newColor) return image;
    dfs(image, sr, sc, newColor);
    return image;
}

void dfs(vector<vector<int>>& image, int x, int y, int newColor) {
    int n = image.size(), m = image[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || image[x][y] != oldColor) return;

    image[x][y] = newColor;
    dfs(image, x - 1, y, newColor);
    dfs(image, x, y - 1, newColor);
    dfs(image, x, y + 1, newColor);
    dfs(image, x + 1, y, newColor);
    // image[x][y] = newColor;
}

// BFS
constexpr static int dx[4] = {-1, 0, 0, 1};
constexpr static int dy[4] = {0, -1, 1, 0};
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int n = image.size(), m = image[0].size();
    int oldColor = image[sr][sc];
    if (oldColor == newColor) return image;
    queue<pair<int, int>> q;
    image[sr][sc] = newColor;
    q.push(make_pair(sr, sc));
    while (!q.empty()) {
        auto kv = q.front();
        q.pop();
        // image[kv.first][kv.second] = -1;
        for (int i = 0; i < 4; i++) {
            int x = kv.first + dx[i], y = kv.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && image[x][y] == oldColor) {
                q.push(make_pair(x, y));
                image[x][y] = newColor;
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (image[i][j] == -1) image[i][j] = newColor;
    //     }
    // }
    return image;
}