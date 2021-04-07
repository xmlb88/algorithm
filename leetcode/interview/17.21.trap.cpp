#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 暴力
int trap(vector<int>& height) {
    int n = height.size();
    int res = 0;
    for (int i = 1; i < n - 1; ++i) {
        int left_max = INT_MIN;
        for (int j = 0; j < i; ++j) {
            left_max = max(left_max, height[j]);
        }

        int right_max = INT_MIN;
        for (int j = i + 1; j < n; ++j) {
            right_max = max(right_max, height[j]);
        }

        if (min(left_max, right_max) - height[i] > 0) {
            res += min(left_max, right_max) - height[i];
        }
    }
    return res;
}

// 暴力优化
// l_max, r_max初始化为height[i]
int trap(vector<int>& height) {
    int n = height.size();
    int res = 0;
    for (int i = 1; i < n - 1; ++i) {
        int l_max = height[i], r_max = height[i];
        for (int j = 0; j < i; ++j) {
            l_max = max(l_max, height[j]);
        }

        for (int j = i + 1; j < n; ++j) {
            r_max = max(r_max, height[j]);
        }

        res += min(l_max, r_max) - height[i];
    }
    return res;
}

// [0,1,0,2,1,0,1,3,2,1,2,1]
// DP 预处理
// 先计算出数组
// [4, 2, 0, 3, 2, 5]
// left:[4, 4, 4, 4, 4, 5]
// right:[5, 5, 5, 5, 5, 5]
int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int n = height.size();
    int res = 0;
    
    vector<int> left_max(n), right_max(n);
    left_max[0] = height[0];
    right_max[n - 1] = height[n - 1];

    for (int i = 1; i < n; ++i) {
        left_max[i] = max(left_max[i - 1], height[i]);
    }

    for (int i = n - 2; i >= 0; --i) {
        right_max[i] = max(right_max[i + 1], height[i]);
    }

    for (int i = 1; i < n - 1; ++i) {
        res += min(left_max[i], right_max[i]) - height[i];
    }
    return res;
}

// 双指针
int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int n = height.size();
    int left = 0, right = n - 1;
    int left_max = height[0], right_max = height[n - 1];
    int res = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            res += left_max - height[left];
            ++left;
            left_max = max(left_max, height[left]);
        } else {
            res += right_max - height[right];
            --right;
            right_max = max(right_max, height[right]);
        }
    }
    return res;
}

int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int n = height.size();
    int left = 0, right = n - 1;
    int left_max = height[0], right_max = height[n - 1];
    int res = 0;
    while (left < right) {
        if (left_max < right_max) {
            res += left_max - height[left];
            ++left;
            left_max = max(left_max, height[left]);
        } else {
            res += right_max - height[right];
            --right;
            right_max = max(right_max, height[right]);
        }
    }
    return res;
}

int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int n = height.size();
    int left = 1, right = n - 2;
    int l_max = height[0], r_max = height[n - 1];
    int res = 0;
    while (left <= right) {
        l_max = max(l_max, height[left]);
        r_max = max(r_max, height[right]);

        if (l_max < r_max) {
            res += l_max - height[left];
            ++left;
        } else {
            res += r_max - height[right];
            --right;
        }
    }
    return res;
}

// 单调栈
int trap(vector<int>& height) {
    int res = 0;
    stack<int> st;
    int n = height.size();
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty()) break;
            int left = st.top();
            int currWidth = i - left - 1;
            int currHeight = min(height[left], height[i]) - height[top];
            res += currWidth * currHeight;
        }
        st.push(i);
    }
    return res;
}