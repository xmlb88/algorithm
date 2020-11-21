#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS
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

// BFS
bool findWhether

