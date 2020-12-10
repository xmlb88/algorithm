#include <iostream>
#include <vector>
using namespace std;

// 贪心
int matrixScore(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size();
    int res = m * (1 << (n - 1));

    for (int j = 1; j < n; j++) {
        int nOnes = 0;
        for (int i = 0; i < m; i++) {
            if (A[i][0] == 1) {
                nOnes += A[i][j];
            } else {
                nOnes += (1 - A[i][j]);
            }
        }
        int k = max(nOnes, m - nOnes);
        res += k * (1 << (n - j - 1));
    }
    return res;
}

// review 2020年12月9日17:32:45
int matrixScore(vector<vector<int>>& A) {
    int n = A.size();
    if (n == 0) return 0;
    int m = A[0].size();

    int sum = n << (m - 1);
    for (int j = 1; j < m; j++) {
        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (A[i][0] == 1) {
                ones += A[i][j];
            } else ones += (1 - A[i][j]);
        }
        int k = max(ones, n - ones);
        sum += k << (m - j - 1);
    }
    return sum;
}