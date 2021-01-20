#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 
int res = INT_MAX;
int num = 0;
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    dfs(target, startFuel, 0, stations, -1);
    return res == INT_MAX ? -1 : res;
}

void dfs(int target, int startFuel, int start, vector<vector<int>>& stations, int index) {
    int canGet = start + startFuel;
    if (canGet >= target) {
        res = min(res, num);
        return;
    }

    for (int i = index + 1; i < stations.size(); i++) {
        if (stations[i][0] >= start && stations[i][0] <= canGet) {
            num++;
            dfs(target, startFuel - (stations[i][0] - start) + stations[i][1], stations[i][0], stations, i);
            num--;
        }
    }
}

// 优先队列 + 贪心
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int num = 0;
    priority_queue<int> gas;

    for (vector<int>& station : stations) {
        if (station[0] <= startFuel) {
            gas.push(station[1]);
        }
    }

    while (startFuel < target && !gas.empty()) {
        int start = startFuel;
        startFuel += gas.top();
        gas.pop();
        num++;
        for (vector<int>& station : stations) {
            if (station[0] > start && station[0] <= startFuel) {
                gas.push(station[1]);
            }
        }
    }
    return startFuel >= target ? num : -1;
}

// dp
// dp[i]表示加i次油能行驶的最远距离
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int n = stations.size();
    vector<long long> dp(n + 1);
    dp[0] = startFuel;
    for (int i = 0; i < n; i++) {
        for (int t = i; t >= 0; t--) {
            if (dp[t] >= stations[i][0])
                dp[t + 1] = max(dp[t + 1], dp[t] + stations[i][1]);
        }
    }

    for (int i = 0; i <= n; i++) {
        if (dp[i] >= target) return i;
    }
    return -1;
}

// 官方优先队列 + 贪心
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> pq;
    int ans = 0, prev = 0;
    for (vector<int>& station : stations) {
        int location = station[0];
        int capacity = station[1];
        startFuel -= location - prev;

        while (!pq.empty() && startFuel < 0) {
            startFuel += pq.top();
            pq.pop();
            ans++;
        }

        if (startFuel < 0) return -1;
        pq.push(capacity);
        prev = location;
    }

    startFuel -= target - prev;
    while (!pq.empty() && startFuel < 0) {
        startFuel += pq.top();
        pq.pop();
        ans++;
    }
    if (startFuel < 0) return -1;
    return ans;
}