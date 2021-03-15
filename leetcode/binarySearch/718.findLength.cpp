#include <iostream>
#include <vector>
using namespace std;

// violence
int findLength(vector<int>& A, vector<int>& B) {
    int max_length = 0;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            if (A[i] != B[j]) continue;

            int length = 0;
            int li = i, lr = j;
            while (li < A.size() && lr < B.size() && A[li++] == B[lr++]) length++;
            max_length = max(max_length, length);
        }
    }
    return max_length;
}

// dp
int findLength(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n, vector<int> (m, 0));
    int max_length = 0;

    for (int i = 0; i < m; ++i) {
        if (A[0] == B[i]) dp[0][i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        if (A[i] == B[0]) dp[i][0] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (A[i] == B[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = 0;

            max_length = max(max_length, dp[i][j]);
        }
    }

    return max_length;
}