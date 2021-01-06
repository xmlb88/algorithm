#include <iostream>
#include <vector>
using namespace std;

// 用i, j遍历上下行号
// 行上的和保存到b数组，对b数组求最大子数组和
vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return {};
    int m = matrix[0].size();
    int maxSum = INT_MIN;
    vector<int> res(4);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> b(m, 0);
            for (int p = i; p <= j; p++) {
                for (int q = 0; q < m; q++) {
                    b[q] += matrix[p][q];
                }
            }

            int dp = b[0], begin = 0;
            if (dp > maxSum) {
                maxSum = dp;
                res[0] = i;
                res[1] = 0;
                res[2] = j;
                res[3] = 0;
            }

            for (int r = 1; r < m; r++) {
                if (dp > 0) {
                    dp += b[r];
                } else {
                    dp = b[r];
                    begin = r;
                }

                if (dp > maxSum) {
                    maxSum = dp;
                    res[0] = i;
                    res[1] = begin;
                    res[2] = j;
                    res[3] = r;
                }
            }
        }
    }
    return res;
}


// 优化时间复杂度，边向下遍历，边计算
vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return {};
    int m = matrix[0].size();
    int maxSum = INT_MIN;
    vector<int> res(4);

    for (int i = 0; i < n; i++) {
        vector<int> b(m, 0);
        for(int j = i; j < n; j++) {
            int begin = 0, sum = 0;
            for (int q = 0; q < m; q++) {
                b[q] += matrix[j][q];

                if (sum > 0) {
                    sum += b[q];
                } else {
                    sum = b[q];
                    begin = q;
                }

                if (sum > maxSum) {
                    maxSum = sum;
                    res[0] = i;
                    res[1] = begin;
                    res[2] = j;
                    res[3] = q;
                }
            }
        }
    }
    return res;
}