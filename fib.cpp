/*
 * @Author: your name
 * @Date: 2020-06-15 19:59:02
 * @LastEditTime: 2020-06-15 20:10:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Algorithm\fib.cpp
 */ 


#include <iostream>
#include <vector>
using namespace std;

int helper(vector<int>& memo, int n) {
    if (n == 1 || n == 2) return 1;

    if (memo[n] != 0) return memo[n];
    memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
    return memo[n];
}

int fib(int N) {
    if (N < 1) return 0;
    vector<int> memo(N + 1, 0);
    return helper(memo, N);
}

int main(){
    cout << fib(15) << endl;
    return 0;
}