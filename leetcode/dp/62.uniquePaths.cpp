#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> path(m, vector<int> (n, 1));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            path[i][j] = path[i - 1][j] + path[i][j - 1];
        }
    }
    return path[m - 1][n - 1];
}

int uniquePaths(int m, int n) {
    vector<int> path(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            path[j] = path[j - 1] + path[j];
        }
    }
    return path[n - 1];
}