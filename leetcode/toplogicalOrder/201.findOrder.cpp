#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// BFS
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> edges(numCourses);
    vector<int> indeg(numCourses);

    for (const vector<int>& info : prerequisites) {
        edges[info[1]].emplace_back(info[0]);
        ++indeg[info[0]];
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : edges[u]) {
            --indeg[v];
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    return order.size() == numCourses ? order : vector<int> ();
}


// DFS
// bool valid = true;
stack<int> st;

vector<int> findOrder(int numCourses, vector<vector<int>>& prereisites) {
    vector<vector<int>> edges(numCourses);
    vector<int> visited(numCourses, 0);

    for (const vector<int>& info : prereisites) {
        edges[info[1]].emplace_back(info[0]);
    }

    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            dfs(i, edges, visited);
        }
    }

    if (st.size() != numCourses) return {};
    vector<int> res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

void dfs(int u, vector<vector<int>>& edges, vector<int>& visited) {
    visited[u] = 1;
    for (int v : edges[u]) {
        if (visited[v] == 0) {
            dfs(v, edges, visited);
        } else if (visited[v] == 1) {
            return;
        }
    }

    visited[u] = 2;
    st.push(u);
}