#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ±©Á¦ try
double median(vector<int>& nums, int left, int right, int k) {
    priority_queue<int> q;
    for (; left <= right; left++) {
        q.push(nums[left]);
    }

    if (k & 1) {
        for (int i = 0; i < k / 2; i++) {
            q.pop();
        }
        return static_cast<double>(q.top());
    } else {
        for (int i = 1; i < k / 2; i++) {
            q.pop();
        }
        int temp = q.top();
        q.pop();
        return (temp / 2.0) + (q.top() / 2.0);
    }
}

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<double> res;
    int left = 0, right = k - 1;
    for (; right < n; left++, right++) {
        res.push_back(median(nums, left, right, k));
    }
    return res;
}

//