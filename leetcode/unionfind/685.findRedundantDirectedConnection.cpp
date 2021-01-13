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
    vector<int> findRedundantDirectedConnection(vector<vector<int>> edges) {
        int n = edges.size();
        unionFind uf(n + 1);
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);
        int conflict = -1, cycle = -1;
        for (int i = 0; i < n; i++) {
            vector<int> edge = edges[i];
            if (parent[edge[1]] != edge[1]) {
                conflict = i;
            } else {
                parent[edge[1]] = edge[0];
                int fx = uf.find(edge[0]), fy = uf.find(edge[1]);
                if (fx == fy) {
                    cycle = i;
                } else {
                    uf.unionSet(fx, fy);
                }
            }
        }

        if (conflict < 0) {
            return edges[cycle];
        } else {
            vector<int> conflictEdge = edges[conflict];
            if (cycle >= 0) {
                return {parent[conflictEdge[1]], conflictEdge[1]};
            } else {
                return conflictEdge;
            }
        }
    }
};
