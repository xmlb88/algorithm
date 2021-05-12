#include <iostream>
#include <vector>
#include <string>
using namespace std;

// violence TLE
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> res;
    for (auto& quer : queries) {
        int x = 0;
        for (int i = quer[0]; i <= quer[1]; ++i) {
            x ^= arr[i];
        }
        res.push_back(x);
    }
    return res;
}

// 类似前缀和 前缀异或
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();
    vector<int> preXor(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        preXor[i] = preXor[i - 1] ^ arr[i - 1];
    }

    vector<int> res;
    for (const auto& quer : queries) {
        res.push_back(preXor[quer[1] + 1] ^ preXor[quer[0]]);
    }
    return res;
}