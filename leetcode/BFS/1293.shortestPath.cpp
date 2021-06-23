#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int res = INT_MAX;
vector<pair<int, int>> pos = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
void dfs(vector<vector<int>>& grid, int left_k, int x, int y, unordered_set<int>& path, int step) {
    int n = grid.size(), m = grid[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m) return;

    if (step > res) return;

    if (grid[x][y] == 1) --left_k;
    if (left_k < 0) return;

    int node = x * 100 + y;
    if (path.find(node) != path.end()) return;
    path.insert(node);

    if (x == n - 1 && y == m - 1) {
        res = min(res, step);
    }

    if (res == n + m - 2) return;

    for (auto [dx, dy] : pos) {
        dfs(grid, left_k, x + dx, y + dy, path, step + 1);
    }

    path.erase(node);
}

int shortestPath(vector<vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size();
    unordered_set<int> path;
    dfs(grid, k, 0, 0, path, 0);
    return res == INT_MAX ? -1 : res;
}

int main() {
    // vector<vector<int>> grid = {
    //     {0, 0, 0},
    //     {1, 1, 0},
    //     {0, 0, 0},
    //     {0, 1, 1},
    //     {0, 0, 0}
    // };

    // int k = 1;

    vector<vector<int>> grid = {
        {0, 1, 0, 1},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 1},
        {0, 1, 0, 0}
    };
    int k = 18;
    cout << shortestPath(grid, k) << endl;
}


// BFS
struct node {
    int x;
    int y;
    int left_k;
    node(int _x, int _y, int _left_k) : x(_x), y(_y), left_k(_left_k) {}
};

vector<pair<int, int>> pos = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int shortestPath(vector<vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size();
    if (k >= m + n - 3) return m + n - 2;
    k = min(k, m + n - 3);
    vector<vector<vector<int>>> visited(n, vector<vector<int>> (m, vector<int> (k + 1, false)));

    queue<node> q;
    q.push(node(0, 0, k));
    int step = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto t = q.front();
            q.pop();
            int x = t.x, y = t.y, left_k = t.left_k;
            if (x < 0 || x >= n || y < 0 || y >= m) continue;

            if (visited[x][y][left_k]) continue;
            visited[x][y][left_k] = true;

            if (grid[x][y] == 1) --left_k;
            if (left_k < 0) continue;

            if (x == n - 1 && y == m - 1) return step;
            for (auto [dx, dy] : pos) {
                q.push(node(x + dx, y + dy, left_k));
            }
        }
        ++step;
    }
    return -1;
}