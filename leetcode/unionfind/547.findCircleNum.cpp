#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// i j连接
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


// review 2021年7月16日10:20:47
// 
// 并查集

class unionFind {
private:
    vector<int> f, rank;
    int unionCount;

public:
    unionFind(int n) : f(n), rank(n, 1), unionCount(n) {
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        if (x == f[x]) return x;
        return f[x] = find(f[x]);
    }

    void unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;

        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        f[fy] = fx;
        rank[fx] += rank[fy];
        --unionCount;
    }

    int getUnionCount() {
        return unionCount;
    }
};

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    unionFind uf(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isConnected[i][j] == 1) {
                uf.unionSet(i, j);
            }
        }
    }
    return uf.getUnionCount();
}
