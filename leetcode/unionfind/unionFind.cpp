#include <iostream>
#include <vector>
using namespace std;

class unionFind {
private:
    int unionCount;
    vector<int> f, rank;
public:
    unionFind(int n) : unionCount(n), f(n), rank(n, 1) {
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        if (f[x] == x) return x;
        f[x] = find(f[x]);
        return f[x];
    }

    bool unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return false;

        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }

        rank[fx] += rank[fy];
        f[fy] = fx;
        unionCount--;
        return true;
    }

    int getUnionCount() {
        return unionCount;
    }
};

class unionFind {
private:
    vector<int> f, rank;
    int unionCount;
public:
    unionFind(int n) : f(n), rank(n, 1), unionCount(n) {
        // iota(f.begin(), f.end(), 0);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
    }

    int find(int x) {
        if (f[x] != x) {
            f[x] = find(f[x]);
        }
        return f[x];
    }

    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return false;

        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        f[fy] = fx;
        rank[fx] += rank[fy];
        --unionCount;
        return true;
    }
};