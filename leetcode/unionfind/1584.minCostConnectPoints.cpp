#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Kruskal ���鼯ά��
// class unionFind {
// private:
//     vector<int> f, rank;
// public:
//     unionFind(int n) {
//         rank.resize(n, 1);
//         f.resize(n);
//         iota(f.begin(), f.end(), 0);
//     }

//     int find(int x) {
//         if (f[x] == x) return x;
//         f[x] = find(f[x]);
//         return f[x];
//     }

//     int unionSet(int x, int y) {
//         int fx = find(x), fy = find(y);
//         if (fx == fy) return false;

//         if (rank[fx] < rank[fy]) {
//             swap(fx, fy);
//         }
//         f[fy] = fx;
//         rank[fx] += rank[fy];
//         return true;
//     }
// };

// struct Edge {
//     int len, x, y;
//     Edge(int len, int x, int y) : len(len), x(x), y(y) {}
// };

// int minCostConnectPoints(vector<vector<int>>& points) {
//     auto dist = [&](int x, int y) -> int {
//         return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
//     };

//     int n = points.size();
//     unionFind uf(n);
//     vector<Edge> edges;
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             edges.emplace_back(dist(i, j), i, j);
//         }
//     }

//     sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
//         return a.len < b.len;
//     });

//     int res = 0, num = 1;
//     for (auto& [len, x, y] : edges) {
//         if (uf.unionSet(x, y)) {
//             res += len;
//             num++;
//             if (num == n) break;
//         }
//     }
//     return res;
// }

// Kruskal
class unionFind {
private:
    vector<int> f, rank;
public:
    unionFind(int n) {
        rank.resize(n, 1);
        f.resize(n);
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
        return true;
    }
};

struct Edge {
    int len, x, y;
    Edge(int len, int x, int y) : len(len), x(x), y(y) {}
};

class Solution {
public:
    int dist(vector<vector<int>>& points, int i, int j) {
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> edges;
        int n = points.size();
        unionFind uf(n);

        // �������еı�
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.emplace_back(dist(points, i, j), i, j);
            }
        }

        // �߰��մ�С��������
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.len < b.len;
        });

        // ����ȡ��edges�бߺ͵㣬���2��û���ӹ���len�����
        // ��������num = ���еĵ�n����
        int res = 0, num = 1;
        for (auto& edge : edges) {
            if (uf.unionSet(edge.x, edge.y)) {
                res += edge.len;
                num++;
                if (num == n) break;
            }
        }
        return res;
    }
};


// Prim
int prim(vector<vector<int>>& points, int start) {
    int n = points.size();
    int res = 0;
    // ��pointsת��Ϊ�ڽӾ���,��һ�����п���
    vector<vector<int>> g(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            g[i][j] = dist;
            g[j][i] = dist;
        }
    }

    // ��¼V[i]��Vnew���������
    vector<int> lowcost(n, INT_MAX);
    // ��¼V[i]�Ƿ���뵽��Vnew
    vector<int> v(n, -1);

    // �Ƚ�start���뵽Vnew
    v[start] = 0;
    for (int i = 0; i < n; i++) {
        if (i == start) continue;
        lowcost[i] = g[i][start];
    }

    // ʣ��n - 1���ڵ�δ���뵽Vnew������
    for (int i = 1; i < n; i++) {
        // �ҳ���ʱv�У���Vnew����ĵ�
        int minIdx = -1;
        int minVal = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (v[j] == 0) continue;
            if (lowcost[j] < minVal) {
                minIdx = j;
                minVal = lowcost[j];
            }
        }

        // ���õ����Vnew������lowcost��v
        res += minVal;
        v[minIdx] = 0;
        lowcost[minIdx] = -1;

        // ���¼���v�����еĵ��lowcost
        for (int j = 0; j < n; j++) {
            if (v[j] == -1 && g[j][minIdx] < lowcost[j]) {
                lowcost[j] = g[j][minIdx];
            }
        }
    }

    return res;
}

int minCostConnectPoints(vector<vector<int>>& points) {
    return prim(points, 0);
}


// Prim ���ȶ����Ż�
int minCostConnectPoints(vector<vector<int>>& points) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n = points.size(), res = 0;
    vector<bool> vi(points.size(), false);

    pq.push({0, 0});
    while (!pq.empty() && n) {
        auto [d, p1] = pq.top();
        pq.pop();
        if (vi[p1]) continue;

        res += d;
        vi[p1] = true;
        n--;

        for (int p2 = 0; p2 < points.size(); p2++) {
            if (vi[p2]) continue;
            int dis = abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
            pq.push({dis, p2});
        }
    }
    return res;
}

// Kruskal + ���鼯
class unionFind {
private:
    vector<int> f, rank;
public:
    unionFind(int n) {
        rank.resize(n, 1);
        f.resize(n);
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
        f[fy] = fx;
        rank[fx] += rank[fy];
        return true;
    }
};

struct Edge {
    int len, x, y;
    Edge(int len, int x, int y) : len(len), x(x), y(y) {}
};

class Solution {
public:
    int dis(vector<vector<int>>& points, int x, int y) {
        return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edges;
        unionFind uf(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.emplace_back(dis(points, i, j), i, j);
            }
        }

        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.len < b.len;
        });

        int res = 0, num = 1;
        for (auto& edge : edges) {
            if (uf.unionSet(edge.x, edge.y)) {
                res += edge.len;
                num++;
                if (num == n) break;
            }
        }
        return res;
    }
};

// Prim + ���ȶ���
int minCostConnectPoints(vector<vector<int>>& points) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n = points.size(), res = 0;
    vector<bool> vi(points.size(), false);
    pq.push({0, 0});

    while (!pq.empty() && n) {
        auto [len, p1] = pq.top();
        pq.pop();

        if (vi[p1]) continue;
        vi[p1] = true;
        res += len;
        n--;

        for (int i = 0; i < points.size(); i++) {
            if (vi[i]) continue;
            int dis = abs(points[i][0] - points[p1][0]) + abs(points[i][1] - points[p1][1]);
            pq.push({dis, i});
        }
    }
    return res;
}