#include <iostream>
#include <vector>
using namespace std;

// wa
bool check(vector<int>& houses, vector<int>& heaters, int radius) {
    vector<pair<int, int>> range;
    for (const int& i : heaters) {
        range.emplace_back(i - radius, i + radius);
    }

    for (const int& h : houses) {
        bool inRange = false;
        for (auto& pair : range) {
            if (h >= pair.first && h <= pair.second) {
                inRange = true;
                break;
            }
        }
        if (!inRange) return false;
    }
    return true;
}

int findRadius(vector<int>& houses, vector<int>& heaters) {
    int left = 0, right = max(*max_element(houses.begin(), houses.end()), *max_element(heaters.begin(), heaters.end()));
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(houses, heaters, mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    vector<int> houses = {1, 5};
    vector<int> heaters = {10};
    cout << findRadius(houses, heaters) << endl;
}

// 暴力
int findRadius(vector<int>& houses, vector<int>& radius) {
    int max_radius = 0;
    for (const int& h : houses) {
        int dis = INT_MAX;
        for (const int& r : radius) {
            dis = min(dis, abs(h - r));
        }
        max_radius = max(max_radius, dis);
    }
    return max_radius;
}

// 二分优化
// TODO:

int findRadius(vector<int>& houses, vector<int>& heaters) {
    int res = 0;
    int n = heaters.size();
    sort(heaters.begin(), heaters.end());
    for (auto house : houses) {
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (house > heaters[mid]) left = mid + 1;
            else right = mid;
        }
        int dist1 = (right == 0) ? INT_MAX : abs(house - heaters[right - 1]);
        int dist2 = (right == n) ? INT_MAX : abs(house - heaters[right]);
        res = max(res, min(dist1, dist2));
    }
    return res;
}