#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// i j¡¨Ω”
void unite(vector<int>& fa, int& count, int i, int j) {
    int fi = findf(fa, i);
    int fj = findf(fa, j);
    if (fi != fj) {
        fa[fi] = fj;
        count--;
    }
}

int findf(vector<int>& fa, int x) {
    if (fa[x] == x) {
        return x;
    } else {
        int f = fa[x];
        fa[x] = findf(fa, f);
        return fa[x];
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    if (n == 0) return 0;

    vector<int> fa(n);
    int count = n;
    iota(fa.begin(), fa.end(), 0);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isConnected[i][j] == 1) {
                unite(fa, count, i, j);
            }
        }
    }

    return count;
}

