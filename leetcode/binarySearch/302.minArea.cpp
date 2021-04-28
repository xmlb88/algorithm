#include <iostream>
#include <vector>
using namespace std;

int up, down, _left, _right;
vector<vector<int>> visited;
void dfs(vector<vector<char>>& image, int x, int y) {
    if (x < up) up = x;
    if (x > down) down = x;
    if (y < _left) _left = y;
    if (y > _right) _right = y;
    visited[x][y] = 1;

    if (x - 1 >= 0 && visited[x - 1][y] == 0 && image[x - 1][y] == '1') dfs(image, x - 1, y);
    if (x + 1 < image.size() && visited[x + 1][y] == 0 && image[x + 1][y] == '1') dfs(image, x + 1, y);
    if (y - 1 >= 0 && visited[x][y - 1] == 0 && image[x][y - 1] == '1') dfs(image, x, y - 1);
    if (y + 1 < image[0].size() && visited[x][y + 1] == 0 && image[x][y + 1] == '1') dfs(image, x, y + 1);
}

int minArea(vector<vector<char>>& image, int x, int y) {
    int n = image.size(), m = image[0].size();
    visited.resize(n, vector<int> (m, 0));
    up = x; down = x; _left = y; _right = y;
    dfs(image, x, y);
    return (down - up + 1) * (_right - _left + 1);
}

int main() {
    vector<vector<char>> image = {
        {'0', '0', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '1', '0', '0'}
    };
    cout << minArea(image, 0, 2) << endl;
}

// TODO: