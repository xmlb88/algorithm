#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (oldColor == newColor) return image;
    dfs(image, sr, sc, oldColor, newColor);
    return image;
}

void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor) {
    int n = image.size(), m = image[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (image[i][j] != oldColor) return;
    image[i][j] = newColor;

    dfs(image, i - 1, j, oldColor, newColor);
    dfs(image, i, j - 1, oldColor, newColor);
    dfs(image, i, j + 1, oldColor, newColor);
    dfs(image, i + 1, j, oldColor, newColor);
}