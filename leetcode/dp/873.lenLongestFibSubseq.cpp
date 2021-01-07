#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;


// set±©Á¦
int lenLongestFibSubseq(vector<int>& arr) {
    set<int> s(arr.begin(), arr.end());
    int n = arr.size();

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = arr[j], y = arr[i] + arr[j];
            int count = 2;
            while (s.find(y) != s.end()) {
                int temp = x + y;
                x = y;
                y = temp;
                count++;
            }
            res = max(res, count);
        }
    }
    return res >= 3? res : 0;
}

// dp
int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    if (n <= 2) return 0;
    unordered_map<int, int> intMap;
    for (int i = 0; i < n; i++) {
        intMap[arr[i]] = i;
    }

    vector<vector<int>> dp(n, vector<int>(n, 2));
    int len = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = arr[j] - arr[i];
            if (intMap.count(diff)) {
                int index = intMap[diff];
                if (index < i) {
                    dp[i][j] = dp[index][i] + 1;
                }
            }
            len = max(len, dp[i][j]);
        }
    }

    return len >= 3? len : 0;
}

// dp
int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> index;
    for(int i = 0; i < n; i++) {
        index[arr[i]] = i;
    }

    unordered_map<int, int> longest;
    int ans = 0;
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < k; j++) {
            if (arr[k] - arr[j] < arr[j] && index.count(arr[k] - arr[j])) {
                int i = index[arr[k] - arr[j]];
                longest[j * n + k] = longest[i * n + j] + 1;
                ans = max(ans, longest[j * n + k] + 2);
            }
        }
    }
    return ans >= 3? ans : 0;
}