#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TODO:
// https://leetcode-cn.com/problems/network-delay-time/solution/dirkdtra-by-happysnaker-vjii/
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> edge(n + 1);
    for (auto& time : times) {
        edge[time[0]].push_back(make_pair(time[1], time[2]));
    }

    queue<pair<int, int>> q;
    vector<int> visited(n + 1, -1);
    q.push(make_pair(k, 0));
    visited[k] = 0;

    while (!q.empty()) {

    }
}