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

// øÏÀŸ≈≈–Ú
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    int n = points.size();
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {
        vec.push_back(make_pair(i, points[i][0] * points[i][0] + points[i][1] * points[i][1]));
    }

    sort_partition(vec, K, 0, vec.size() - 1);
    vector<vector<int>> res;
    for (int i = 0; i < K; i++) {
        res.push_back(points[vec[i].first]);
    }
    return res;
}

void sort_partition(vector<pair<int, int>>& vec, int k, int l, int r) {
    if (l >= r) return;
    
    int index = quicksort(vec, l, r);
    if (index == k) return;
    else if (index < k) {
        sort_partition(vec, k, index + 1, r);
    } else if (index > k) {
        sort_partition(vec, k, l, index - 1);
    }
}

int quicksort(vector<pair<int, int>>& vec, int l, int r) {
    auto kv = vec[l];
    while (l < r) {
        while (l < r && vec[r].second >= kv.second) {
            r--;
        }
        if (l < r) {
            vec[l] = vec[r];
        }
        while (l < r && vec[l].second <= kv.second) {
            l++;
        }
        if (l < r) {
            vec[r] = vec[l];
        }
    }
    vec[l] = kv;
    return l;
}

