#include <iostream>
#include <vector>
using namespace std;

// 滚动数组
vector<int> getRow(int rowIndex) {
    vector<int> lastRow, row;
    for (int i = 0; i <= rowIndex; ++i) {
        row.resize(i + 1);
        row[0] = row[i] = 1;
        for (int j = 1; j < i; j++) {
            row[j] = lastRow[j - 1] + lastRow[j];
        }
        lastRow = row;
    }
    return row;
}

// 只用一个数组
vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex + 1);
    row[0] = 1;
    for (int i = 1; i <= rowIndex; ++i) {
        for (int j = i; j > 0; --j) {
            row[j] += row[j - 1];
        }
    }
    return row;
}