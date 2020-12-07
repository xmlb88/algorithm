#include <iostream>
#include <vector>
using namespace std;

// Ì°ÐÄ
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

