#include <iostream>
#include <vector>
using namespace std;

// 暴力法
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> res(n, 0);
    for (auto booking : bookings) {
        for (int i = booking[0]; i <= booking[1]; i++) {
            res[i - 1] += booking[2];
        }
    }
    return res;
}

// 差分数组
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    int n = bookings.size();
    // 构造差分数组,初始化为0
    vector<int> diff(n, 0);

    for (auto booking : bookings) {
        int left = booking[0] - 1;
        int right = booking[1];
        diff[left] += booking[2];
        if (right < n) {
            diff[right] -= booking[2];
        }
    }

    // 还原数组
    vector<int> ans(n);
    ans[0] = diff[0];
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] + diff[i];
    }

    return ans;
}


// class
class difference{
private:
    vector<int> diff;
public:
    difference(vector<int>& nums) {
        int n = nums.size();
        assert(n > 0);
        diff.resize(n);
        diff[0] = nums[0];
        for (int i = 1; i < n; i++) {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    void increase(int i, int j, int increment) {
        diff[i] += increment;
        if (j + 1 < diff.size()) {
            diff[j + 1] -= increment;
        }
    }

    vector<int> result() {
        vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }

};

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> nums(n, 0);
    difference dif = difference(nums);
    for (auto booking : bookings) {
        dif.increase(booking[0] - 1, booking[1] - 1, booking[2]);
    }
    return dif.result();
}