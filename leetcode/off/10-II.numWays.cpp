#include <iostream>
#include <vector>
using namespace std;

int base = 1000000007;
int numWays(int n) {
    if (n == 0 || n == 1) return 1;
    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] % base + dp[i - 2] % base;
    }
    return dp[n] % base;
}

// 只于前2个数有关，优化空间
int base = 1000000007;
int numWays(int n) {
    if (n == 0 || n == 1) return 1;
    int first = 1, second = 1;
    for (int i = 2; i <= n; i++) {
        int sum = first % base + second % base;
        first = second;
        second = sum;
    }
    return second % base;
}

