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
int maxTurbulenceSize(vector<int>& A) {
    int n = A.size();

    if (n <= 1) return n;
    if (n == 2) {
        if (A[0] == A[1]) return 1;
        return 2;
    }

    int left = 0, right = 1;
    int maxLen = 0;

    while (right < n - 1) {
        ++right;
        if ((A[right] > A[right - 1] && A[right - 2] > A[right - 1]) || (A[right] < A[right - 1] && A[right - 2] < A[right - 1])) {
            maxLen = max(maxLen, right - left + 1);
        } else {
            if (A[right] != A[right - 1]) {
                left = right - 1;
                maxLen = max(maxLen, 2);
            } else {
                left = right;
                ++right;
                maxLen = max(maxLen, 1);
            }
        }
    }
    return maxLen;
}

// 4 8 12 16
// TODO:
int maxTurbulenceSize(vector<int>& arr) {
    int n = arr.size();
    int maxLen = 1;
    int left = 0, right = 0;

    while (right < n - 1) {
        if (left == right) {
            if (arr[left] == arr[left + 1]) {
                left++;
            }
            right++;
        } else {
            if (arr[right - 1] < arr[right] && arr[right] > arr[right + 1]) {
                right++;
            } else if (arr[right - 1] > arr[right] && arr[right] < arr[right + 1]) {
                right++;
            } else {
                left = right;
            }
        }
        maxLen = max(maxLen, right - left + 1);
    }
}