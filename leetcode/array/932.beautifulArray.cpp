#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// 1 2 3    1 3 2
// 1 2 3 4 5    
vector<int> beautifulArray(int n) {
    if (n == 1) return {1};
    vector<int> res;
    for (auto i : beautifulArray((n + 1) / 2)) {
        res.push_back(2 * i - 1);
    }

    for (auto i : beautifulArray(n / 2)) {
        res.push_back(2 * i);
    }
    return res;
}

// º«“‰ªØµ›πÈ
unordered_map<int, vector<int>> m = {{1, {1}}};
vector<int> beautifulArray(int n) {
    if (m.find(n) != m.end()) {
        return m[n];
    }

    vector<int> res;
    for (auto odd : beautifulArray((n + 1) / 2)) {
        res.push_back(2 * odd - 1);
    }

    for (auto even : beautifulArray(n / 2)) {
        res.push_back(2 * even);
    }

    m[n] = res;
    return res;
}

// Œª≈≈–Ú
vector<int> beautifulArray(int n) {
    vector<int> beauty;
    for (int i = 1; i <= n; ++i) {
        beauty.push_back(i);
    }

    sort(beauty.begin(), beauty.end(), [=] (int a, int b) {
        int bit = 1;
        while ((a & bit) == (b & bit)) {
            bit <<= 1;
        }
        return (a & bit) > (b & bit);
    });

    return beauty;
}