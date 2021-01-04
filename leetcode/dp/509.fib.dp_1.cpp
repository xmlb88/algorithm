#include<iostream>
#include<vector>
using namespace std;

// 暴力递归
int fib(int N) {
    if (N == 0) return 0;
    if (N == 1 || N == 2) return 1;
    return fib(N - 1) + fib(N - 2);
}


// 带备忘录的递归
int fib(int N) {
    if (N < 1) return 0;
    // 备忘录初始化0
    vector<int> memo(N + 1, 0);
    // 带备忘录递归
    return helper(memo, N);
}

int helper(vector<int>& memo, int N) {
    // base case
    if (N == 1 || N == 2) return 1;

    // 已经计算过
    if (memo[N] != 0) return memo[N];
    memo[N] = helper(memo, N - 1) + helper(memo, N - 2);
    return memo[N];
}

// dp数组迭代
int fib(int N) {
    if (N == 0) return 0;
    if (N == 1 || N == 2) return 1;
    vector<int> dp(N + 1, 0);
    // base case
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
}

// 只用2个状态，降低空间复杂度
int fib(int N) {
    if (N == 0) return 0;
    if (N == 1 || N == 2) return 1;

    int pre = 1, cur = 1;
    for (int i = 3; i <= N; i++) {
        int sum = pre + cur;
        pre = cur;
        cur = sum;
    }

    return cur;
}

#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        int temp = prev + curr;
        prev = curr;
        curr = temp;
    }
    return curr;
}