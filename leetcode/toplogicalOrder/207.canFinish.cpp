#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 广度优先搜索模拟
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> indeg(numCourses);

        for (const vector<int>& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int u = q.front();
            q.pop();
            for (int v : edges[u]) {
                --indeg[v];
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return visited == numCourses;
    }
};


// DFS
bool valid = true;
bool canFinish(int numCourses, vector<vector<int>> prerequisites) {
    vector<vector<int>> edges(numCourses);
    vector<int> visited(numCourses, 0);

    for (const auto& info : prerequisites) {
        edges[info[1]].push_back(info[0]);
    }

    for (int i = 0; i < numCourses && valid; ++i) {
        if (!visited[i]) {
            dfs(i, edges, visited);
        }
    }

    return valid;
}

void dfs(int u, vector<vector<int>>& edges, vector<int>& visited) {
    visited[u] = 1;
    for (int v : edges[u]) {
        if (visited[v] == 0) {
            dfs(v, edges, visited);
            if (!valid) {
                return;
            }
        }
        else if (visited[v] == 1) {
            valid = false;
            return;
        }
    }
    visited[u] = 2;
}


class Solution {
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 标记每个节点的状态，0 = 未搜索，1 = 搜索中，2 = 已完成
    vector<int> visited;
    // 用数组模拟栈，下标0为栈底，n - 1为栈顶
    vector<int> result;
    // 判断有向图中是否有环
    bool valid = true;

public:
    void dfs(int u) {
        // 将节点标记为搜索中
        visited[u] = 1;
        // 搜索其相邻节点
        // 只要发现有环，立刻停止搜索
        for (int v : edges[u]) {
            // 如果未搜索，那么搜索相邻节点
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            // 如果搜索中说明找到了环
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        // 将节点标记为已完成
        visited[u] = 2;
        result.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }

        // 每次挑选一个未搜索的节点，开始进行深度优先搜索
        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        if (!valid) return {};
        // 如果没有环，那么就有拓扑排序
        // 注意下标0为栈底，因此需要将数组反序输出
        reverse(result.begin(), result.end());
        return result;
    }
};