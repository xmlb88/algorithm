#include <iostream>
#include <vector>
using namespace std;

// Kruskal + 并查集 最小生成树
class unionFind {
private:
    vector<int> f, rank;
    int setCount;
public:
    unionFind(int n) {
        setCount = n;
        f = vector<int> (n);
        rank = vector<int> (n, 1);
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
        setCount--;
        return true;
    }

    int getSetCount() {
        return setCount;
    }
};

vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
    int m = edges.size();
    for (int i = 0; i < m; i++) {
        edges[i].push_back(i);
    }

    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    
    int value = 0;
    unionFind uf_std(n);
    for (const vector<int>& edge : edges) {
        if (uf_std.unionSet(edge[0], edge[1])) {
            value += edge[2];
        }
    }

    vector<vector<int>> res(2);

    for (int i = 0; i < m; i++) {
        // 判断是否是关键边
        unionFind uf(n);
        int v = 0;
        for (int j = 0; j < m; j++) {
            if (i != j && uf.unionSet(edges[j][0], edges[j][1])) {
                v += edges[j][2];
            }
        }

        if (uf.getSetCount() != 1 || (uf.getSetCount() == 1 && v > value)) {
            res[0].push_back(edges[i][3]);
            continue;   // 是关键边就不用再判断伪关键边
        }

        // 判断是否伪关键边
        uf = unionFind(n);
        uf.unionSet(edges[i][0], edges[i][1]);
        v = edges[i][2];
        for (int j = 0; j < m; j++) {
            if (i != j && uf.unionSet(edges[j][0], edges[j][1])) {
                v += edges[j][2];
            }
        }

        if (v == value) {
            res[1].push_back(edges[i][3]);
        }
    }
    return res;
}