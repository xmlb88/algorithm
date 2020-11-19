#include <iostream>
#include <vector>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b)
                                        {return a[1] < b[1];});
    
    int count = 1;
    int end = points[0][1];
    for (int i = 1; i < points.size(); i++) {
        int start = points[i][0];
        if (start > end) {
            end = points[i][1];
            count++;
        }
    }
    return count;
}