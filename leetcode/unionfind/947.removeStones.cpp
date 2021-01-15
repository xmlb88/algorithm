#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// DFS
int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    if (n == 0) return 0;
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            count++;
            dfs(stones, visited, i);
        }
    }
    return n - count;
}

void dfs(vector<vector<int>>& stones, vector<bool>& visited, int i) {
    if (visited[i]) return;
    visited[i] = true;

    for (int j = 0; j < stones.size(); j++) {
        if (visited[j]) continue;
        if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
            dfs(stones, visited, j);
        }
    }
}

// 并查集
class unionFind {
private:
    vector<int> f;
    int count;
public:
    unionFind(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        count = n;
    }

    int find(int x) {
        if (f[x] == x) return x;
        f[x] = find(f[x]);
        return f[x];
    }

    void unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        f[fy] = fx;
        count--;
    }

    int getCount() {
        return count;
    }
};

int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    unionFind uf(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                uf.unionSet(i, j);
            }
        }
    }
    return n - uf.getCount();
}

// 建图 + DFS
void dfs(int x, vector<vector<int>>& edge, vector<int>& visited) {
    visited[x] = true;
    for (auto& y : edge[x]) {
        if (!visited[y]) {
            dfs(y, edge, visited);
        }
    }
}

int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    vector<vector<int>> edge(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                edge[i].push_back(j);
            }
        }
    }

    vector<int> visited(n);
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            num++;
            dfs(i, edge, visited);
        }
    }
    return n - num;
}

// 优化建图 + DFS
void dfs(int x, vector<vector<int>>& edge, vector<bool>& visited) {
    visited[x] = true;
    for (auto& y : edge[x]) {
        if (!visited[y]) {
            dfs(y, edge, visited);
        }
    }
}

//[[0,0],[0,2],[1,1],[2,0],[2,2]]
// rec:
// [0] : [0, 1]
// [1] : [2]
// [2] : [3, 4]
// [10000] : [0, 3]
// [10001] : [2]
// [10002] : [1, 4]
// rec:
// [1, 3]
// [0, 4]
// []
// [0, 4]
// [1, 3]
int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    vector<vector<int>> edge(n);
    unordered_map<int, vector<int>> rec;

    for (int i = 0; i < n; i++) {
        rec[stones[i][0]].push_back(i);
        rec[stones[i][1] + 10000].push_back(i);
    }

    for (auto& [_, vec] : rec) {
        int k = vec.size();
        for (int i = 1; i < k; i++) {
            edge[vec[i - 1]].push_back(vec[i]);
            edge[vec[i]].push_back(vec[i - 1]);
        }
    }

    vector<bool> visited(n, false);
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            num++;
            dfs(i, edge, visited);
        }
    }
    return n - num;
}

// 优化建图 + 并查集
class DisjointSetUnion {
private:
    unordered_map<int, int> f, rank;
public:
    int find(int x) {
        if (!f.count(x)) {
            f[x] = x;
            rank[x] = 1;
        }
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    void unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;

        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }

        rank[fx] += rank[fy];
        f[fy] = fx;
    }

    int numberOfConnectedComponent() {
        int num = 0;
        for (auto& [x, fa] : f) {
            if (x == fa) {
                num++;
            }
        }
        return num;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSetUnion dsu;
        for (int i = 0; i < n; i++) {
            dsu.unionSet(stones[i][0], stones[i][1] + 10000);
        }
        return n - dsu.numberOfConnectedComponent();
    }
};