#include<iostream>
#include<vector>
using namespace std;

int change(int amount, vector<int>& coins) {
    int n = coins.size();

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (j - coins[i - 1] >= 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][amount];
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<int> dp(amount + 1);

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (j - coins[i] >= 0) {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
    }

    return dp[amount];
}


int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (j - coins[i - 1] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
        }
    }

    return dp[n][amount];
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (j - coins[i] >= 0) {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
    }

    return dp[amount];
}


int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (j - coins[i - 1] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
        }
    }

    return dp[n][amount];
}

// dp[i][j]
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int> (amount + 1, 0));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= amount; ++j) {
            if (j < coins[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
        }
    }

    return dp[n][amount];
}