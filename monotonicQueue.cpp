#include<iostream>
#include<queue>
#include<vector>
#include<deque>
using namespace std;

class monotonicQueue {
private:
    deque<int> data;
public:
    void push(int n) {
        while (!data.empty() && data.back() < n) {
            data.pop_back();
        }
        data.push_back(n);
    }

    int max() {
        return data.front();
    }

    void pop(int n) {
        if (!data.empty() && data.front() == n) {
            data.pop_front();
        }
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    monotonicQueue window;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        if (i < k - 1) {
            window.push(nums[i]);
        } else {
            window.push(nums[i]);
            window.pop(nums[i - k + 1]);
            result.push_back(window.max());
        }
    }

    return result;
}

int main() {
    vector<int> nums = {2, 4, 6, 2, 7, 4, 9};
    vector<int> res = maxSlidingWindow(nums, 3);
    for (int num : res) {
        cout << num << " ";
    }
    return 0;
}