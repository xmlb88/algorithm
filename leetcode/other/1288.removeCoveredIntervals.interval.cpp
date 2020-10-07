#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

int removeCoveredIntervals(vector<vector<int>> intervals) {

    sort(intervals.begin(), intervals.end(), cmp);

    int left = intervals[0][0];
    int right = intervals[0][1];

    int res = 0;
    for (int i = 1; i < intervals.size(); i++) {
        // ���һ���ҵ���������
        if (left <= intervals[i][0] && right >= intervals[i][1]) {
            res++;
        }

        // ��������ҵ��ཻ���䣬�ϲ�
        if (right >= intervals[i][0] && right <= intervals[i][1]) {
            right = intervals[i][1];
        }

        // ���������ȫ���뽻�����������յ�
        if (right < intervals[i][0]) {
            left = intervals[i][0];
            right = intervals[i][1];
        }
    }

    return intervals.size() - res;
}


int removeCoveredIntervals(vector<vector<int>> intervals) {

    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    int left = intervals[0][0];
    int right = intervals[0][1];

    int res = 0;
    for (int i = 1; i < intervals.size(); i++) {
        // ���һ���ҵ���������
        if (left <= intervals[i][0] && right >= intervals[i][1]) {
            res++;
        }

        // ��������ҵ��ཻ���䣬�ϲ�
        if (right >= intervals[i][0] && right <= intervals[i][1]) {
            right = intervals[i][1];
        }

        // ���������ȫ���뽻�����������յ�
        if (right < intervals[i][0]) {
            left = intervals[i][0];
            right = intervals[i][1];
        }
    }

    return intervals.size() - res;
}

    // bool cmp(const vector<int>& a, const vector<int>& b) {
    //     if (a[0] == b[0]) return a[1] > b[1];
    //     return a[0] < b[0];
    // }