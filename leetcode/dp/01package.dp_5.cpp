#include<iostream>
#include<vector>
using namespace std;

int package(vector<int>& w, vector<int>& val, int weight) {
    int n = w.size();
    vector<vector<int>> dp(n + 1, vector<int>(weight + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= weight; j++) {
            if (j - w[i - 1] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + val[i - 1]);
            }
        }
    }

    return dp[n][weight];
}

int main() {
    vector<int> w = {1, 2, 4, 6};
    vector<int> val = {2, 4, 3, 5};
    int weight = 10;
    cout << package(w, val, weight) << endl;
}