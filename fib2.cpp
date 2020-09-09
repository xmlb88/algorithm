/*
 * @Author: your name
 * @Date: 2020-06-15 20:18:58
 * @LastEditTime: 2020-06-15 20:22:37
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Algorithm\fib2.cpp
 */ 

#include <iostream>
#include <vector>
using namespace std;

int fib(int N) {
    vector<int> dp(N + 1, 0);
    dp[1] = dp[2] = 1;
    for(int i = 3; i < N + 1; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
}

int main() {
    cout << fib(15) << endl;
    return 0;
}