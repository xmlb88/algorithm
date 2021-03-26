#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysDivByK(vector<int>& A, int K) {
    int count = 0, n = A.size();
    for (int start = 0; start < n; ++start) {
        int sum = 0;
        for (int end = start; end >= 0; end--) {
            sum += A[end];
            if (sum % K == 0) ++count;
        }
    }
    return count;
}

// 前缀和
int subarraysDivByK(vector<int>& A, int K) {
    int n = A.size();
    vector<int> preSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        preSum[i + 1] = preSum[i] + A[i];
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if ((preSum[j + 1] - preSum[i]) % K == 0) ++count;
        }
    }
    return count;
}

// 前缀和 + 哈希
int subarraysDivByK(vector<int>& A, int K) {
    int n = A.size();
    unordered_map<int, int> mp;
    mp[0] = 1;
    int pre = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        pre += A[i];
        if (mp.find((pre % K + K) % K) != mp.end()) {
            count += mp[(pre % K + K) % K];
        }
        mp[(pre % K + K) % K]++;
    }
    return count;
}