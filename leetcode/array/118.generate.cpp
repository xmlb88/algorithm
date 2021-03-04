#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res(numRows);
    for (int i = 0; i < numRows; i++) {
        res[i].resize(i + 1);
        res[i][0] = res[i][i] = 1;
        for (int j = 1; j < i; j++) {
            res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
        }
    }
    return res;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i = 0; i < numRows; ++i) {
        vector<int> row(i + 1);
        row[0] = row[i] = 1;
        for (int j = 1; j < i; ++j) {
            row[j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        res.push_back(row);
    }
    return res;
}