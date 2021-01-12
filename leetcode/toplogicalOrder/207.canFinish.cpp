#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// �����������ģ��
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
    // �洢����ͼ
    vector<vector<int>> edges;
    // ���ÿ���ڵ��״̬��0 = δ������1 = �����У�2 = �����
    vector<int> visited;
    // ������ģ��ջ���±�0Ϊջ�ף�n - 1Ϊջ��
    vector<int> result;
    // �ж�����ͼ���Ƿ��л�
    bool valid = true;

public:
    void dfs(int u) {
        // ���ڵ���Ϊ������
        visited[u] = 1;
        // ���������ڽڵ�
        // ֻҪ�����л�������ֹͣ����
        for (int v : edges[u]) {
            // ���δ��������ô�������ڽڵ�
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            // ���������˵���ҵ��˻�
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        // ���ڵ���Ϊ�����
        visited[u] = 2;
        result.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }

        // ÿ����ѡһ��δ�����Ľڵ㣬��ʼ���������������
        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        if (!valid) return {};
        // ���û�л�����ô������������
        // ע���±�0Ϊջ�ף������Ҫ�����鷴�����
        reverse(result.begin(), result.end());
        return result;
    }
};