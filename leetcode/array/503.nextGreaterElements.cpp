#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n * 2; i++) {
        while (!st.empty() && nums[st.top() % n] < nums[i % n]) {
            res[st.top() % n] = nums[i % n];
            st.pop();
        }
        st.push(i % n);
    }

    return res;
}

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    stack<int> st;

    for (int i = n * 2 - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }
        res[i % n] = st.empty() ? -1 : st.top();
        st.push(nums[i % n]);
    }
    return res;
}