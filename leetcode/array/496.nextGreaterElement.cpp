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

// µπ◊≈»Î’ª
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