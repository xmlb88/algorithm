#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int nthUglyNumber(int n) {
    vector<int> ugly(n);
    int p_2 = 0, p_3 = 0, p_5 = 0;
    ugly[0] = 1;
    for (int i = 1; i < n; ++i) {
        ugly[i] = min(min(ugly[p_2] * 2, ugly[p_3] * 3), ugly[p_5] * 5);
        if (ugly[i] == ugly[p_2] * 2) ++p_2;
        if (ugly[i] == ugly[p_3] * 3) ++p_3;
        if (ugly[i] == ugly[p_5] * 5) ++p_5;
    }
    return ugly[n - 1];
}

// ×îÐ¡¶Ñ
int nthUglyNumber(int n) {
    priority_queue<long long, vector<long long>, greater<long long>> min_heap;
    unordered_set<long long> s;
    vector<int> three{2, 3, 5};

    long long res = 1;
    min_heap.push(1);
    for (int i = 0; i < n; ++i) {
        res = min_heap.top();
        min_heap.pop();
        for (auto& x : three) {
            if (s.count(res * x) == 0) {
                min_heap.push(res * x);
                s.insert(res * x);
            }
        }
    }
    return res;
}