#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> intervals) {
    if (intervals.size() == 0 || intervals.size() == 1) return intervals;
    vector<vector<int>> result;
    vector<int> res;
    sort(intervals.begin(), intervals.end());
    res = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
        if (res[1] >= intervals[i][0]) {
            res[1] = max(intervals[i][1], res[1]);
        } else {
            result.push_back(res);
            res = intervals[i];
        }
        if (i == intervals.size() - 1) result.push_back(res);
    }

    return result;
}