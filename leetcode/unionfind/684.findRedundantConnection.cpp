#include <iostream>
#include <vector>
using namespace std;

class unionFind {
private:
    vector<int> f, rank;
    int n;
public:
    unionFind(int _n) {
        n = _n;
        rank.resize(n, 1);
        f.resize(n);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        if (f[x] == x) {
            return x;
        } else {
            f[x] = find(f[x]);
        }
        return f[x];
    }

    void unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;

        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        f[fy] = fx;
        rank[fx] += rank[fy];
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unionFind uf(n);
        for (const vector<int>& edge : edges) {
            int fx = uf.find(edge[0] - 1), fy = uf.find(edge[1] - 1);
            if (fx == fy) {
                return edge;
            } else {
                uf.unionSet(edge[0] - 1, edge[1] - 1);
            }
        }
        return {};
    }
};
