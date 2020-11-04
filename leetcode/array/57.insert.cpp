#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    if (intervals.empty()) {
        res.push_back(newInterval);
        return res;
    }
    int flag = 0;
    for (int i = 0; i < intervals.size(); i++) {
        if (intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
        } else if (intervals[i][0] > newInterval[1]) {
            res.push_back(newInterval);
            flag = 1;
            for (; i < intervals.size(); i++) {
                res.push_back(intervals[i]);
            }
        } else {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
    }
    if (!flag) res.push_back(newInterval);
    return res;
}