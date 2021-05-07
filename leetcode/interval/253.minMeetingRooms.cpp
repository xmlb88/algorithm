#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 最小堆
int minMeetingRooms(vector<vector<int>>& intervals) {
    priority_queue<int, vector<int>, greater<int>> q;
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    for (auto& inter : intervals) {
        if (q.empty()) {
            q.push(inter[1]);
            continue;
        }

        if (inter[0] >= q.top()) {
            q.pop();
        }
        q.push(inter[1]);
    }
    return q.size();
}

// interesting 分开处理
int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<int> startM, endM;
    for (auto& inter : intervals) {
        startM.push_back(inter[0]);
        endM.push_back(inter[1]);
    }

    sort(startM.begin(), startM.end());
    sort(endM.begin(), endM.end());
    int s_ptr = 0, e_ptr = 0, room = 0;
    while (s_ptr < startM.size()) {
        if (startM[s_ptr] >= endM[e_ptr]) {
            ++e_ptr;
        } else {
            ++room;
        }
        ++s_ptr;
    }
    return room;
}