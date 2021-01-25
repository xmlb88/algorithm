#include <iostream>
#include <string>                                               
#include <vector>
using namespace std;

class unionFind {
private:
    int unionCount;
    vector<int> f, rank;
public:
    unionFind(int n) {
        unionCount = n;
        rank.resize(n, 1);
        f.resize(n);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        if (f[x] == x) return x;
        f[x] = find(f[x]);
        return f[x];
    }

    void unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;

        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }

        rank[fx] += rank[fy];
        f[fy] = fx;
        unionCount--;
    }

    int getUnionCount() {
        return unionCount;
    }
};

int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();
    int count = n * n * 4;
    unionFind uf(count);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int index = i * n * 4 + j * 4;
            if (grid[i][j] == ' ') {
                uf.unionSet(index, index + 1);
                uf.unionSet(index, index + 2);
                uf.unionSet(index, index + 3);
            } else if (grid[i][j] == '/') {
                uf.unionSet(index, index + 3);
                uf.unionSet(index + 1, index + 2);
            } else if (grid[i][j] == '\\') {
                uf.unionSet(index, index + 1);
                uf.unionSet(index + 2, index + 3);
            }

            if (j < n - 1) {
                uf.unionSet(index + 1, index + 4 + 3);
            }

            if (i < n - 1) {
                int nextline = (i + 1) * n * 4 + j * 4;
                uf.unionSet(index + 2, nextline);
            }
        }
    }
    return uf.getUnionCount();
}