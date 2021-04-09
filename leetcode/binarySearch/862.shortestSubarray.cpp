#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int>& A, int K, int len) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += A[i];
    }

    if (sum >= K) return true;
    for (int i = len; i < A.size(); ++i) {
        sum += A[i] - A[i - len];
        if (sum >= K) return true;
    }
    return false;
}

int shortestSubarray(vector<int>& A, int K) {
    int n = A.size();
    for (int i = 1; i <= n; i++) {
        if (check(A, K, i)) return i;
    }
    return -1;
}

// TODO: