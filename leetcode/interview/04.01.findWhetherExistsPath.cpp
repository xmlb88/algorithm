#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// DFS 超时
bool find = false;
vector<bool> visited;
bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
    visited.assign(n, false);
    dfs(graph, start, target);
    return find;
}

void dfs(vector<vector<int>>& graph, int start, int target) {
    if (start == target) {
        find = true;
        return;
    }

    if (visited[start]) return;
    visited[start] = true;

    for (auto edge : graph) {
        if (edge[0] == start) {
            dfs(graph, edge[1], target);
        }
    }
}

// BFS 超时
bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int new_start = q.front();
        q.pop();
        if (new_start == target) return true;
        for (auto edge : graph) {
            if (edge[0] == new_start && visited[edge[1]] == false) {
                q.push(edge[1]);
                visited[edge[1]] = true;
            }
        }
    }
    return false;
}

// 优化DFS unordered_map存储能到达的点，查询时O1
unordered_map<int, unordered_set<int>> m;
vector<bool> visited;
bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
    visited.assign(n, false);
    for (auto edge : graph) {
        m[edge[0]].insert(edge[1]);
    }
    return dfs(start, target);
}

bool dfs(int start, int target) {
    if (start == target) return true;

    if (visited[start]) return false;
    visited[start] = true;
    for (auto& neighbor : m[start]) {
        if (dfs(neighbor, target)) {
            return true;
        }
    }
    return false;
}
