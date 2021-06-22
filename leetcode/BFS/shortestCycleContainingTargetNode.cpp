#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solve(vector<vector<int>>& graph, int target) {
    int n = graph.size();
    vector<int> visited(n, 0);
    queue<int> q;
    q.push(target);
    int len = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int s = 0; s < size; ++s) {
            int now = q.front();
            q.pop();
            if (now == target && len != 0) return len;
            if (visited[now]) continue;
            visited[now] = 1;
            for (int val : graph[now]) {
                q.push(val);
            }
        }
        ++len;
    }
    return -1;
}

int solve(vector<vector<int>>& graph, int target) {
    int n = graph.size();
    queue<int> q;
    vector<int> visited(n, 0);
    int len = 0;
    q.push(target);
    while (!q.empty()) {
        int size = q.size();
        for (int s = 0; s < size; ++s) {
            auto now = q.front();
            q.pop();
            visited[now] = 1;
            for (int neighbor : graph[now]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                } else if (neighbor == target) return len + 1;
            }
        }
        ++len;
    }
    return -1;
}

int main() {
    vector<vector<int>> graph = {{0}};
    cout << solve(graph, 0) << endl;
}