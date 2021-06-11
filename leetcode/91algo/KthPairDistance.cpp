#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// ¶Ñ TLE
int solve(vector<int>& nums, int k) {
    priority_queue<int> q;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            int dis = abs(nums[i] - nums[j]);
            if (q.size() < k + 1) {
                q.push(dis);
            } else {
                if (dis < q.top()) {
                    q.pop();
                    q.push(dis);
                }
            }
        }
    }
    return q.top();
}

// ¶þ·Ö
bool check(int diff, int k, vector<int>& nums) {
    long count = 0;
    int n = nums.size(), r = 0;
    for (int l = 0; l < n; ++l) {
        while (r < n && nums[r] - nums[l] <= diff) {
            r++;
        }
        count += (r - l - 1);
    }
    return count >= k;
}

int solve(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    k++;
    int left = 0, right = nums.back() - nums[0];
    int res = INT_MAX;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid, k, nums)) {
            res = min(res, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}


int main() {
    vector<int> nums = {1, 5, 3, 2};
    cout << solve(nums, 2) << endl;
}