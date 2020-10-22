#include <iostream>
using namespace std;

int cuttingRope(int n) {
    
}

int cuttingRope(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int curMax = 0;
        for (int j = 1; j < i; j++) {
            curMax = max(curMax, max(j * (i - j), dp[i - j] * j));
        }
        dp[i] = curMax;
    }
    return dp[n];
}

int cuttingRope(int n) {
    if (n <= 3) return n - 1;
    long long res = 1;
    while (n > 4) {
        n -= 3;
        res = res * 3 % 1000000007;
    }
    return res * n % 1000000007;
}