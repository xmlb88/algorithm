#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
using namespace std;

/*
class unionFind {
private:
    vector<int> f, rank;
    int unionCount;
public:
    unionFind(int n) {
        f.resize(n);
        rank.resize(n, 1);
        iota(f.begin(), f.end(), 0);
        unionCount = n; 
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

int makeConnected(int n, vector<vector<int>>& connections) {
    unionFind uf(n);
    int extraCount = 0;
    
    for (vector<int>& conn : connections) {
        if (!uf.unionSet(conn[0], conn[1])) {
            extraCount++;
        }
    }

    int unionCount = uf.getUnionCount();
    int need = unionCount - 1;
    return extraCount >= need ? need : -1;
}

int main() {
    vector<vector<int>> connections = {
        {0, 1}, {0, 2}, {0, 3}, {1, 2}
    };
    cout << makeConnected(6, connections) << endl;
}
*/

// DFS
int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;

    vector<vector<int>> edges(n);
    for (vector<int>& conn : connections) {
        edges[conn[0]].push_back(conn[1]);
        edges[conn[1]].push_back(conn[0]);
    }

    vector<bool> visited(n, false);
    int connCount = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connCount++;
            dfs(edges, visited, i);
        }
    }
    return connCount - 1;
}

void dfs(vector<vector<int>>& edges, vector<bool>& visited, int i) {
    if (visited[i]) return;
    visited[i] = true;

    for (int& index : edges[i]) {
        if (!visited[index]) {
            dfs(edges, visited, index);
        }
    }
}


// BFS
int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;

    vector<vector<int>> edges(n);
    for (vector<int>& conn : connections) {
        edges[conn[0]].push_back(conn[1]);
        edges[conn[1]].push_back(conn[0]);
    }

    int num = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            num++;
            BFS(edges, visited, i);
        }
    }
    return num - 1;
}

void BFS(vector<vector<int>>& edges, vector<bool>& visited, int i) {
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while (!q.empty()) {
        int point = q.front();
        q.pop();
        for (int& index : edges[point]) {
            if (!visited[index]) {
                q.push(index);
                visited[index] = true;
            }
        }
    }
}