#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp{triangle[0][0]};
    for (int i = 1; i < n; ++i) {
        vector<int> new_dp;
        new_dp.push_back(dp[0] + triangle[i][0]);
        for (int j = 1; j < i; ++j) {
            new_dp.push_back(min(dp[j - 1], dp[j]) + triangle[i][j]);
        }
        new_dp.push_back(dp.back() + triangle[i].back());
        dp = new_dp;
    }
    return *min_element(dp.begin(), dp.end());
}

// int main() {
//     vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
//     cout << minimumTotal(triangle) << endl;
// }

// 从底向上递推
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n + 1, vector<int> (n + 1));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        }
    }
    return dp[0][0];
}

// 空间优化
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(triangle.back());
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        }
    }
    return dp[0];
}

// 原地dp
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}