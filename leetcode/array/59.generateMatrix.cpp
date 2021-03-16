#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    if (n == 0) return {};
    vector<vector<int>> res(n, vector<int> (n));
    int num = 1;
    int up = 0, down = n - 1;
    int left = 0, right = n - 1;
    while (true) {
        for (int j = left; j <= right; ++j) res[up][j] = num++;
        if (++up > down) break;
        for (int i = up; i <= down; ++i) res[i][right] = num++;
        if (--right < left) break;
        for (int j = right; j >= left; --j) res[down][j] = num++;
        if (--down < up) break;
        for (int i = down; i >= up; --i) res[i][left] = num++;
        if (++left > right) break;
    }
    return res;
}

vector<vector<int>> generateMatrix(int n) {
    if (n == 0) return {};
    vector<vector<int>> res(n, vector<int>(n));
    int up = 0, down = n - 1;
    int left = 0, right = n - 1;
    int num = 1;
    while (true) {
        for (int j = left; j <= right; ++j) res[up][j] = num++;
        if (++up > down) break;
        for (int i = up; i <= down; ++i) res[i][right] = num++;
        if (--right < left) break;
        for (int j = right; j >= left; --j) res[down][j] = num++;
        if (--down < up) break;
        for (int i = down; i >= up; --i) res[i][left] = num++;
        if (++left > right) break;
    }
    return res;
}