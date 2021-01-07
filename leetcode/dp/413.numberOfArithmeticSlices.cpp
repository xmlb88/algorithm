#include <iostream>
#include <vector>
using namespace std;

// self thought
int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    if (n <= 2) return 0;
    vector<int> len;
    int count = 2;
    for (int i = 2; i < n; i++) {
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
            count++;
        } else {
            if (count >= 3) len.push_back(count);
            count = 2;
        }
    }
    if (count >= 3) len.push_back(count);

    int res = 0;
    for (int l : len) {
        res += (l - 1) * (l - 2) / 2;
    }
    return res;
}
// 3 : 1
// 4 : 2 + 1
// 5 : 3 + 2 + 1

// 暴力
int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    int count = 0;
    for (int s = 0; s < n - 2; s++) {
        int d = A[s + 1] - A[s];
        for (int e = s + 2; e < n; e++) {
            int i = 0;
            for (i = s + 1; i <= e; i++) {
                if (A[i] - A[i - 1] != d) break;
            }
            if (i > e) count++;
        }
    }
    return count;
}

// 暴力优化
int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    int count = 0;
    for (int s = 0; s < n - 2; s++) {
        int d = A[s + 1] - A[s];
        for (int e = s + 2; e < n; e++) {
            if (A[e] - A[e - 1] == d) count++;
            else break;
        }
    }
    return count;
}

// 递归
int sum = 0;
int numberOfArithmeticSlices(vector<int>& A) {
    slices(A, A.size() - 1);
    return sum;
}

int slices(vector<int>& A, int i) {
    if (i < 2) return 0;

    int ap = 0;
    if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
        ap = 1 + slices(A, i - 1);
        sum += ap;
    } else {
        slices(A, i - 1);
    }
    return ap;
}

// dp
int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    vector<int> dp(n, 0);
    int sum = 0;
    for (int i = 2; i < n; i++) {
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
            dp[i] = 1 + dp[i - 1];
            sum += dp[i];
        }
    }
    return sum;
}

// 优化空间dp
int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    int dp = 0, sum = 0;
    for (int i = 2; i < n; i++) {
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
            dp++;
            sum += dp;
        } else dp = 0;
    }
    return sum;
}