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
        unordered_map<int, vector<int>> mp; // ����վ�빫���Ĺ�ϵͼ
        unordered_set<int> usedBus;         // ����ȥ��
        unordered_set<int> usedStation;     // ����վȥ��
        int ans = 0;
        for (int i = 0; i < routes.size(); ++i) {
            for (int j : routes[i]) {
                mp[j].emplace_back(i); // ��ͼ
            }
        }
        if (mp.find(source) == mp.end() || mp.find(target) == mp.end()) return -1; // �Ҳ���վ������-1
        if (source == target) return 0; // �����ʼ���ǽ�����ֱ�ӷ��� 0
        queue<vector<int>> q;
        q.emplace(mp[source]);  // ������������map��vector
        usedStation.insert(source);
        while (!q.empty()) { // ��ʼ bfs ��������
            int size = q.size();
            ++ans; // ���˴���+1
            for (int _ = 0; _ < size; ++_) {
                auto it = q.front();
                q.pop();
                for (int idx : it) { // idx�ǹ���������
                    if (usedBus.find(idx) != usedBus.end()) continue;
                    for (int tar : routes[idx]) { // �ڶ�Ӧ������·��������վ��
                        if (tar == target) return ans; // �ҵ�վ��
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