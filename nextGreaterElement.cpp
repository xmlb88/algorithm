#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> result(nums.size());
    stack<int> s;

    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= nums[i]) {
            s.pop();
        }

        result[i] = s.empty()? -1 : s.top();
        // if (s.empty()) result.push_back(-1);
        // else result.push_back(s.top());

        s.push(nums[i]);
    }
    return result;
}

int main() {
    vector<int> nums = {2, 6, 3, 5, 3, 4};
    vector<int> res = nextGreaterElement(nums);
    for (auto num : res) {
        cout << num << " ";
    }
    return 0;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    unordered_map<int, int> m;
    vector<int> result;

    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= nums2[i]) {
            s.pop();
        }

        m[nums2[i]] = s.empty()? -1 : s.top();
        s.push(nums2[i]);
    }

    for (int num : nums1) {
        result.push_back(m[num]);
    }

    return result;
}