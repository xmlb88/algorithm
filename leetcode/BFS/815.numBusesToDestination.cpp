#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    if (source == target) return 0;
    unordered_map<int, unordered_set<int>> graph;

    for (auto& route : routes) {
        for (int r : route) {
            for (int b : route) {
                graph[r].insert(b);
                graph[b].insert(r);
            }
        }
    }

    queue<int> q;
    unordered_set<int> visited;
    q.push(source);
    int step = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int s = 0; s < size; ++s) {
            int bus = q.front();
            q.pop();
            for (int next_bus : graph[bus]) {
                if (next_bus == target) return step + 1;
                if (visited.count(next_bus)) continue;
                visited.insert(next_bus);
                q.push(next_bus);
            }
        }
        ++step;
    }
    return -1;
}


int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    if (source == target) return 0;
    unordered_map<int, vector<int>> stationToRoutes;
    for (int i = 0; i < routes.size(); ++i) {
        for (int station : routes[i]) {
            stationToRoutes[station].push_back(i);
        }
    }

    queue<int> q;
    q.push(source);
    unordered_set<int> visited;
    int step = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int s = 0; s < size; ++s) {
            int station = q.front();
            q.pop();
            for (int route : stationToRoutes[station]) {
                for (int bus : routes[route]) {
                    if (bus == target) return step + 1;
                    if (visited.count(bus)) continue;
                    visited.insert(bus);
                    q.push(bus);
                }
            }
        }
        ++step;
    }
    return -1;
}


///

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> mp; // 公交站与公交的关系图
        unordered_set<int> usedBus;         // 公交去重
        unordered_set<int> usedStation;     // 公交站去重
        int ans = 0;
        for (int i = 0; i < routes.size(); ++i) {
            for (int j : routes[i]) {
                mp[j].emplace_back(i); // 建图
            }
        }
        if (mp.find(source) == mp.end() || mp.find(target) == mp.end()) return -1; // 找不到站，返回-1
        if (source == target) return 0; // 如果开始就是结束，直接返回 0
        queue<vector<int>> q;
        q.emplace(mp[source]);  // 队列里面存放了map的vector
        usedStation.insert(source);
        while (!q.empty()) { // 开始 bfs 层序搜索
            int size = q.size();
            ++ans; // 换乘次数+1
            for (int _ = 0; _ < size; ++_) {
                auto it = q.front();
                q.pop();
                for (int idx : it) { // idx是公交的索引
                    if (usedBus.find(idx) != usedBus.end()) continue;
                    for (int tar : routes[idx]) { // 在对应公交的路线里面找站点
                        if (tar == target) return ans; // 找到站点
                        if (usedStation.find(tar) != usedStation.end()) continue;
                        usedStation.insert(tar);
                        q.emplace(mp[tar]);
                    }
                    usedBus.insert(idx);
                }
            }
        }
        return -1;
    }
};