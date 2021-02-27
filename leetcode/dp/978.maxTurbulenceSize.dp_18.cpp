#include <iostream>
#include <vector>
using namespace std;

// dp
int maxTurbulenceSize(vector<int>& A) {
    int n = A.size();
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2 && A[0] != A[1]) return 2;
    if (n == 2 && A[0] == A[1]) return 1;
    vector<int> dp(n, 0);
    dp[0] = 1;
    if (A[1] == A[0]) dp[1] = 1;
    else dp[1] = 2;
    for (int i = 2; i < n; i++) {
        if ((A[i - 1] < A[i - 2] && A[i - 1] < A[i]) || (A[i - 1] > A[i - 2] && A[i - 1] > A[i])) {
            dp[i] = dp[i - 1] + 1;
        } else if (A[i] != A[i - 1]) {
            dp[i] = 2;
        } else dp[i] = 1;
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, dp[i]);
    }

    return res;
}

// int main() {
//     vector<int> test{100,100,100};
//     cout << maxTurbulenceSize(test) << endl;
// }

// TODO:
// sliding window
int maxTurbulenceSize(vector<int>& arr) {
    
}