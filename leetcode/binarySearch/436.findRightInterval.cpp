#include <iostream>
#include <vector>
using namespace std;

// WA
vector<int> findRightInterval(vector<vector<int>>& intervals) {
    vector<int> res;
    int n = intervals.size();
    for (int i = 0; i < n; ++i) {
        int index = -1;
        for (int j = 0; j < n; ++j) {
            if (index == -1 && j != i && intervals[j][0] > intervals[i][1]) {
                index = j;
                continue;
            }

            if (index != -1 && j != i && intervals[j][0] > intervals[i][1] && intervals[j][0] < intervals[index][0]) {
                index = j;
                continue;
            }
        }
        res.push_back(index);
    }
    return res;
}

// violence wrong
vector<int> findRightInterval(vector<vector<int>>& intervals) {
    if (intervals.size() == 1) return {-1};
    vector<int> res;
    for (int i = 0; i < intervals.size(); ++i) {
        int min = INT_MAX;
        int minIndex = -1;
        for (int j = 0; j < intervals.size(); ++i) {
            if (intervals[j][0] >= intervals[i][1] && intervals[j][0] < min) {
                min = intervals[j][0];
                minIndex = j;
            }
        }
        res.push_back(minIndex);
    }
    return res;
}

// TODO: