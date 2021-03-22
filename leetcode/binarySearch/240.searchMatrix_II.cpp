#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0, j = m - 1; i < n && j >= 0; ) {
        if (target == matrix[i][j]) return true;

        if (target > matrix[i][j]) ++i;
        else if (target < matrix[i][j]) --j;
    }
    return false;
}