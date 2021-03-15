#include <iostream>
#include <vector>
using namespace std;

// vector<int> spiralOrder(vector<vector<int>>& matrix) {
//     vector<int> res;
//     if (matrix.empty()) return res;
//     int up = 0, down = matrix.size() - 1;
//     int left = 0, right = matrix[0].size() - 1;

//     while (true) {
//         for (int i = left; i <= right; i++) res.push_back(matrix[up][i]);
//         if (++up > down) break;
//         for (int i = up; i <= down; i++) res.push_back(matrix[i][right]);
//         if (--right < left) break;
//         for (int i = right; i >= left; i--) res.push_back(matrix[down][i]);
//         if (--down < up) break;
//         for (int i = down; i >= up; i--) res.push_back(matrix[i][left]);
//         if (++left > right) break;
//     }

//     return res;
// }


// review 2021Äê3ÔÂ15ÈÕ09:09:38
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.empty()) return res;
    int up = 0, down = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;
    while (true) {
        for (int j = left; j <= right; ++j) res.push_back(matrix[up][j]);
        if (++up > down) break;
        for (int i = up; i <= down; ++i) res.push_back(matrix[i][right]);
        if (--right < left) break;
        for (int j = right; j >= left; --j) res.push_back(matrix[down][j]);
        if (--down < up) break;
        for (int i = down; i >= up; --i) res.push_back(matrix[i][left]);
        if (++left > right) break;
    }
    return res;
}

int main() {
    vector<vector<int>> v = {
        {2, 5, 8},
        {4, 0, -1}
    };

    spiralOrder(v);
}