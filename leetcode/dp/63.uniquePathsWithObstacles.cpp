#include <iostream>
#include <vector>
#include <string>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int> (n, 1));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {

            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }

            if (i == 0 && j == 0) continue;
            if (i == 0) dp[i][j] = dp[i][j - 1];
            else if (j == 0) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

// 优化
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid.at(0).size();
    vector<int> dp(n);
    dp[0] = (obstacleGrid[0][0] == 0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[i][j] == 1) {
                dp[j] = 0;
                continue;
            }

            if (j > 0) {
                dp[j] += dp[j - 1];
            }
        }
    }
    return dp.back();
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> dp(m);
    dp[0] = (obstacleGrid[0][0] == 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (obstacleGrid[j][i] == 1) {
                dp[j] = 0;
                continue;
            }

            if (j > 0) {
                dp[j] += dp[j - 1];
            }
        }
    }
    return dp.back();
}


// review 2021年7月12日15:47:51
// use dp

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int> (n));
    dp[0][0] = 1;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}

// 滚动数组 优化
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> dp(n);
    dp[0] = (obstacleGrid[0][0] == 0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[i][j] == 1) {
                dp[j] = 0;
                continue;
            }

            if (j > 0) {
                dp[j] += dp[j - 1];
            }
        }
    }
    return dp[n - 1];
}