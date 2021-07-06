#include <iostream>
#include <vector>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
                                                {return a[1] < b[1];});

    int count = 0;
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        int start = intervals[i][0];
        if (start >= end) {
            end = intervals[i][1];
        } else {
            count++;
        }
    }
    return count;
}

// review 2021��7��6��11:16:32
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int count = 0;
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
        int start = intervals[i][0];
        if (start >= end) {
            end = intervals[i][1];
        } else ++count;
    }
    return count;
}