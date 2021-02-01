#include <iostream>
#include <vector>
using namespace std;

class unionFind {
private:
    vector<int> f, rank;
    int unionCount;
public:
    unionFind(int n) : f(n), unionCount(n), rank(n, 1) {
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

        if (fx < fy) swap(fx, fy);
        rank[fx] += rank[fy];
        f[fy] = fx;
        unionCount--;
        return true;
    }

    int getUnionCount() {
        return unionCount;
    }
};

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    unionFind ufa(n), ufb(n);
    int res = 0;
    for (auto& edge : edges) {
        if (edge[0] == 3) {
            if (!ufa.unionSet(edge[1] - 1, edge[2] - 1)) {
                ++res;
            } else {
                ufb.unionSet(edge[1] - 1, edge[2] - 1);
            }
        }
    }

    for (auto& edge : edges) {
        if (edge[0] == 1) {
            if (!ufa.unionSet(edge[1] - 1, edge[2] - 1)) {
                ++res;
            }
        } else if (edge[0] == 2) {
            if (!ufb.unionSet(edge[1] - 1, edge[2] - 1)) {
                ++res;
            }
        }
    }

    if (ufa.getUnionCount() != 1 || ufb.getUnionCount() != 1) {
        return -1;
    }
    return res;
}

// review 2021Äê2ÔÂ1ÈÕ18:10:10

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

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    unionFind uf1(n);
    int canDelete = 0;
    for (const vector<int>& edge : edges) {
        if (edge[0] == 3) {
            if (!uf1.unionSet(edge[1] - 1, edge[2] - 1)) {
                canDelete++;
            }
        }
    }

    unionFind uf2 = uf1;

    for (const vector<int>& edge : edges) {
        if (edge[0] == 1) {
            if (!uf1.unionSet(edge[1] - 1, edge[2] - 1)) {
                canDelete++;
            }
        } else if (edge[0] == 2) {
            if (!uf2.unionSet(edge[1] - 1, edge[2] - 1)) {
                canDelete++;
            }
        }
    }

    if (uf1.getUnionCount() != 1 || uf2.getUnionCount() != 1) {
        return -1;
    }
    return canDelete;
}