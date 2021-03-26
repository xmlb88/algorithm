#include <iostream>
#include <vector>
using namespace std;


// violence TLE
int shortestDistance(vector<int>& color, int idx, int target) {
    int dis = 0;
    while (idx + dis < color.size() || idx - dis >= 0) {
        if (idx + dis < color.size() && color[idx + dis] == target)
            return dis;
        if (idx - dis >= 0 && color[idx - dis] == target)
            return dis;
        ++dis;
    }
    return -1;
}

vector<int> shortestDistanceColor(vector<int>& color, vector<vector<int>>& queries) {
    vector<int> distance;
    for (const vector<int>& vec : queries) {
        distance.push_back(shortestDistance(color, vec[0], vec[1]));
    }
    return distance;
}


// 预处理，1 2 3 分开存，二分查找最近idx

int shortestDistance(vector<int>& index, int idx) {
    int n = index.size();
    if (n == 0) return -1;
    int left = 0, right = n - 1;
    int result = INT_MAX;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        result = min(result, abs(index[mid] - idx));
        if (index[mid] == idx) {
            return 0;
        } else if (index[mid] > idx) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

vector<int> shortestDistanceColor(vector<int>& color, vector<vector<int>>& queries) {
    int n = color.size();
    vector<vector<int>> index(3);

    // 预处理
    for (int i = 0; i < n; ++i) {
        index[color[i] - 1].push_back(i);
    }

    vector<int> res;
    for (const vector<int>& vec : queries) {
        res.push_back(shortestDistance(index[vec[1] - 1], vec[0]));
    }
    return res;
}