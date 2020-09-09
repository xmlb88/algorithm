/*
 * @Author: your name
 * @Date: 2020-06-19 20:47:19
 * @LastEditTime: 2020-06-19 20:52:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Algorithm\backpack01.cpp
 */ 

#include <iostream>
#include <vector>
using namespace std;

int backpack(int W, int N, vector<int>& wt, vector<int>& val) {
    //base case
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (w - wt[i - 1] < 0) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            }
        }
    }

    return dp[n][w];
}


int main() {

}