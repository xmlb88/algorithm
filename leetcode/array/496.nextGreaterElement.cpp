#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    unordered_map<int, int> map;
    for (int i = 0; i < nums2.size(); i++) {
        while (!st.empty() && st.top() <= nums2[i]) {
            map[st.top()] = nums2[i];
            st.pop();
        }
        st.push(nums2[i]);
    }

    vector<int> res;
    for (int i = 0; i < nums1.size(); i++) {
        if (map.count(nums1[i]) > 0) res.push_back(map[nums1[i]]);
        else res.push_back(-1);
    }

    return res;
}

// 倒着入栈
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map;
    stack<int> st;
    vector<int> res;

    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }
        map[nums2[i]] = st.empty() ? -1 : st.top();
        st.push(nums2[i]);
    }

    for (int i = 0; i < nums1.size(); i++) {
        res.push_back(map[nums1[i]]);
    }
    return res;
}


// review 2021年3月9日20:23:04
// stack
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    vector<int> res;
    unordered_map<int, int> mp;
    stack<int> st;
    for (int i = 0; i < m; ++i) {
        if (st.empty() || nums2[i] <= nums2[st.top()]) {
            st.push(i);
        } else {
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
    }

    while (!st.empty()) {
        mp[nums2[st.top()]] = -1;
        st.pop();
    }

    for (int i = 0; i < n; i++) {
        res.push_back(mp[nums1[i]]);
    }
    return res;
}

// 优化
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    unordered_map<int, int> mp;
    vector<int> res;
    stack<int> st;

    for (int i = 0; i < m; ++i) {
        while (!st.empty() && st.top() < nums2[i]) {
            mp[st.top()] = nums2[i];
            st.pop();
        }
        st.push(nums2[i]);
    }

    while (!st.empty()) {
        mp[st.top()] = -1;
        st.pop();
    }

    for (int i = 0; i < n; ++i) {
        res.push_back(mp[nums1[i]]);
    }

    return res;
}

// 从后往前
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    unordered_map<int, int> mp;
    vector<int> res;
    stack<int> st;

    for (int i = m - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }
        mp[nums2[i]] = st.empty() ? -1 : st.top();
        st.push(nums2[i]);
    }

    for (int i = 0; i < n; ++i) {
        res.push_back(mp[nums1[i]]);
    }
    return res;
}

// [1, 3, 4, 2]
// stack: 2
// 4
// 

// 可以用vector？
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    unordered_map<int, int> mp;
    vector<int> res;
    vector<int> st;
    for (int i = 0; i < m; ++i) {
        while (!st.empty() && st.back() < nums2[i]) {
            mp[st.back()] = nums2[i];
            st.pop_back();
        }
        st.push_back(nums2[i]);
    }

    while (!st.empty()) {
        mp[st.back()] = -1;
        st.pop_back();
    }

    for (int i = 0; i < n; i++) {
        res.push_back(mp[nums1[i]]);
    }
    return res;
}