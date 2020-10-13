#include <iostream>
#include <vector>
using namespace std;

// int maxTurbulenceSize(vector<int>& A) {
//     int n = A.size();
//     if (n == 0) return 0;
//     if (n == 1) return 1;
//     if (n == 2) return 2;
//     vector<int> dp(n, 0);
//     dp[0] = 1;
//     dp[1] = 2;
//     for (int i = 2; i < n; i++) {
//         if ((A[i - 1] > A[i - 2] && A[i - 1] < A[i]) || (A[i - 1] < A[i - 2] && A[i - 1] > A[i])) {
//             dp[i] = dp[i - 1] + 1;
//         } else {
//             dp[i] = 1;
//         }
//     }

//     int res = 0;
//     for (int i = 0; i < n; i++) {
//         res = max(res, dp[i]);
//     }

//     return res;
// }

// TODO: