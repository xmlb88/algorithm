#include <iostream>
#include <string>
#include <vector>
using namespace std;

int numDecodings(string s) {
    if (s[0] == '0') return 0;
    int n = s.size();
    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        if (s[i - 1] == '0') {
            if (s[i - 2] == '1' || s[i - 2] == '2') {
                dp[i] = dp[i - 2];
            } else return 0;
        } else {
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] >= '1' && s[i - 1] <= '6')) {
                dp[i] = dp[i - 2] + dp[i - 1];
            } else dp[i] = dp[i - 1];
        }
    }
    return dp[n];
}

int numDecodings(string s) {
    if (s[0] == '0') return 0;
    int n = s.size();
    int prev = 1, curr = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            if (s[i - 1] == '1' || s[i - 1] == '2') {
                swap(prev, curr);
            } else return 0;
        } else {
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                int temp = prev + curr;
                prev = curr;
                curr = temp;
            } else {
                prev = curr;
            }
        }
    }
    return curr;
}