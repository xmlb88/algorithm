#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

// TLE
int solve(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i <= n; ++i) {
        pre[i] = pre[i - 1] + nums[i - 1];
    }
    int sum = pre[n];
    if (sum % k == 0) return 0;

    for (int len = 1; len < n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            if ((sum - (pre[i + len] - pre[i])) % k == 0) return len;
        }
    }
    return -1;
}

int solve(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + nums[i - 1];
    }
    int sum = pre[n];
    int target_mod = (sum % k + k) % k;
    if (target_mod == 0) return 0;

    int sub_len = n;
    unordered_map<int, int> m;
    for (int i = 0; i <= n; ++i) {
        int mod = (pre[i] % k + k) % k;
        if (m.find((mod - target_mod + k) % k) != m.end()) {
            sub_len = min(sub_len, i - m[(mod - target_mod + k) % k]);
        }
        m[mod] = i;
    }
    return sub_len == n ? -1 : sub_len;
}

P00121577    105321201905003989
int solve(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int target_mod = (sum % k + k) % k;
    if (target_mod == 0) return 0;

    int min_len = n, pre = 0;
    unordered_map<int, int> m;
    m[0] = -1;
    for (int i = 0; i < n; ++i) {
        pre += nums[i];
        int mod = (pre % k + k) % k;
        if (m.find((mod - target_mod + k) % k) != m.end()) {
            min_len = min(min_len, i - m[(mod - target_mod + k) % k]);
        }
        m[mod] = i;
    }
    return min_len == n ? -1 : min_len;
}

// [1, 8, 6, 4, 5]
//     [0, 1, 9, 15, 19, 24]
// mod [0, 1, 2, 1, 5, 3]
int main() {
    vector<int> nums = {1, 8, 6, 4, 5};
    cout << solve(nums, 7) << endl;
}