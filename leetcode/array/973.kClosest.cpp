#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// ≈≈–Ú ≥¨ ±
static bool cmp(vector<int> a, vector<int> b) {
    return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    vector<vector<int>> res;
    sort(points.begin(), points.end(), cmp);
    for (int i = 0; i < K; i++) {
        res.push_back(points[i]);
    }
    return res;
}

// ¥Û∂•∂—
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < K; i++) {
        q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
    }

    for (int i = K; i < points.size(); i++) {
        int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        if (distance <= q.top().first) {
            q.pop();
            q.emplace(distance, i);
        }
    }

    vector<vector<int>> res;
    while (!q.empty()) {
        res.push_back(points[q.top().second]);
        q.pop();
    }

    return res;
}