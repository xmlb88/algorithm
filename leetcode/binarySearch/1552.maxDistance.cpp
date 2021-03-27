#include <iostream>
#include <vector>
using namespace std;

int maxDistance(vector<int>& position, int m) {
    int n = position.size();
    sort(position.begin(), position.end());
    int left = 1, right = (position[n - 1] - position[0]);
    int ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        int cnt = 0, target = 0;
        for (int i = 0; i < n; ++i) {
            if (position[i] >= target) {
                target = position[i] + mid;
                cnt++;
            }
        }

        if (cnt >= m) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}


bool check(vector<int>& position, int distance, int m) {
    int target = 0, cnt = 0;
    for (int i = 0; i < position.size(); ++i) {
        if (position[i] >= target) {
            ++cnt;
            target = position[i] + distance;
        }
    }
    return cnt >= m;
}

int maxDistance(vector<int>& position, int m) {
    int n = position.size();
    sort(position.begin(), position.end());
    int left = 1, right = position[n - 1] - position[0];
    int ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(position, mid, m)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}