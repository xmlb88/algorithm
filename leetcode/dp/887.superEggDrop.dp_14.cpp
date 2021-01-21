#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

unordered_map<string, int> memo;
int superEggDrop(int K, int N) {
    // base case
    if (K == 1) return N;
    if (N == 0) return 0;

    string key = to_string(K) + "," + to_string(N);
    if (memo.count(key)) return memo[key];

    int res = INT_MAX;
    for (int i = 1; i <= N; i++) {
        res = min(res, max(superEggDrop(K - 1, i - 1), superEggDrop(K, N - i)) + 1);
    }

    memo[key] = res;
    return res;
}


unordered_map<string, int> memo;
int superEggDrop(int K, int N) {
    if (K == 1) return N;
    if (N == 0) return 0;

    string key = to_string(K) + "," + to_string(N);
    if (memo.count(key) > 0) return memo[key];

    int res = INT_MAX;
    for (int i = 1; i <= N; i++) {
        res = min(res, max(superEggDrop(K - 1, i - 1), superEggDrop(K, N - i)) + 1);
    }

    memo[key] = res;
    return res;
}

// 二分

unordered_map<int, int> memo;
int superEggDrop(int K, int N) {
    if (K == 1) return N;
    if (N == 0) return 0;

    // string key = to_string(K) + "," + to_string(N);
    int key = N * 100 + K;
    if (memo.count(key) > 0) return memo[key];

    int res = INT_MAX;
    int left = 1, right = N;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int broken = superEggDrop(K - 1, mid - 1);
        int not_broken = superEggDrop(K, N - mid);
        if (broken > not_broken) {
            right = mid - 1;
            res = min(res, broken + 1);
        } else {
            left = mid + 1;
            res = min(res, not_broken + 1);
        }
    }

    memo[key] = res;
    return res;
}

// 
int superEggDrop(int K, int N) {
    vector<vector<int>> dp(K + 1, vector<int> (N + 1, 0));
    int m = 0;
    while (dp[K][m] < N) {
        m++;
        for (int k = 1; k <= K; k++) {
            dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1;
        }
    }
    return m;
}


// 二分
unordered_map<string, int> memo;
int superEggDrop(int K, int N) {
    if (K == 1) return N;
    if (N == 0) return 0;

    string key = to_string(K) + "," + to_string(N);
    if (memo.count(key) > 0) return memo[key];

    int left = 1, right = N;
    int res = INT_MAX;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int broken = superEggDrop(K - 1, mid - 1);
        int not_broken = superEggDrop(K, N - mid);
        if (broken > not_broken) {
            right = mid - 1;
            res = min(res, broken + 1);
        } else if (broken < not_broken) {
            left = mid + 1;
            res = min(res, not_broken + 1);
        } else if (broken == not_broken) {
            left = right = mid;
            res = min(res, broken + 1);
            memo[key] = res;
            return res;
        }
    }

    int max_left = max(superEggDrop(K - 1, left - 1), superEggDrop(K, N - left));
    int max_right = max(superEggDrop(K - 1, right - 1), superEggDrop(K, N - right));
    res = min(res, min(max_left, max_right) + 1);
    memo[key] = res;
    return res;
}

// ???
unordered_map<string, int> memo;
int superEggDrop(int K, int N) {
    if (K == 1) return N;
    if (N == 0) return 0;

    string key = to_string(K) + "," + to_string(N);
    if (memo.find(key) != memo.end()) return memo[key];

    int lo = 1, hi = N;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        int broken = superEggDrop(K - 1, mid - 1);
        int not_broken = superEggDrop(K, N - mid);

        if (broken < not_broken) lo = mid;
        else if (broken > not_broken) hi = mid;
        else lo = hi = mid;
    }

    int max_lo = max(superEggDrop(K - 1, lo - 1), superEggDrop(K, N - lo));
    int max_hi = max(superEggDrop(K - 1, hi - 1), superEggDrop(K, N - hi));
    int res = 1 + min(max_hi, max_lo);

    memo[key] = res;
    return res;
}


unordered_map<int, int> memo;
int superEggDrop(int K, int N) {
    if (K == 1) return N;
    if (N == 0) return 0;

    int key = N * 100 + K;
    if (memo.find(key) != memo.end()) return memo[key];

    int lo = 1, hi = N;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        int broken = superEggDrop(K - 1, mid - 1);
        int not_broken = superEggDrop(K, N - mid);

        if (broken < not_broken) lo = mid;
        else if (broken > not_broken) hi = mid;
        else lo = hi = mid;
    }

    int max_lo = max(superEggDrop(K - 1, lo - 1), superEggDrop(K, N - lo));
    int max_hi = max(superEggDrop(K - 1, hi - 1), superEggDrop(K, N - hi));
    int res = 1 + min(max_hi, max_lo);

    memo[key] = res;
    return res;
}

// review
int superEggDrop(int K, int N) {
    if (K == 1) return N;
    if (N == 0) return 0;

    for (int i = 1; i <= N; i++) {
        if ()
    }
}