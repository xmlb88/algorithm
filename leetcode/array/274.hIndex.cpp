#include <iostream>
#include <vector>
using namespace std;

int hIndex(vector<int>& citations) {
    int n = citations.size();
    vector<int> cnt(n + 1, 0);
    for (auto c : citations) {
        if (c > n) {
            ++cnt[n];
        } else ++cnt[c];
    }

    int total_cnt = 0;
    for (int i = n; i >= 1; --i) {
        total_cnt += cnt[i];
        if (total_cnt >= i) return i;
    }
    return 0;
}