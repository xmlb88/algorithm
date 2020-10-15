#include <iostream>
#include <vector>
using namespace std;

// 暴力法
int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int ans = 0;
    int n = height.size();
    for (int i = 1; i < n - 1; i++) {
        int l_max = height[i], r_max = height[i];

        for (int j = i; j >= 0; j--) {
            l_max = max(height[j], l_max);
        }

        for (int j = i; j < n; i++) {
            r_max = max(height[j], r_max);
        }

        ans += min(l_max, r_max) - height[i];
    }

    return ans;
}

// 备忘录优化
int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int n = height.size();
    int ans = 0;
    vector<int> l_max(n), r_max(n);
    l_max[0] = height[0];
    r_max[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++) {
        l_max[i] = max(l_max[i - 1], height[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        r_max[i] = max(r_max[i + 1], height[i]);
    }

    for (int i = 1; i < n - 1; i++) {
        ans += min(l_max[i], r_max[i]) - height[i];
    }

    return ans;
}

// 双指针从两边开始

int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int n = height.size();
    int left = 1, right = n - 2;
    int l_max = height[0], r_max = height[n - 1];
    int ans = 0;

    while (left <= right) {
        l_max = max(l_max, height[left]);
        r_max = max(r_max, height[right]);
        if (l_max < r_max) {
            ans += l_max - height[left];
            left++;
        } else {
            ans += r_max - height[right];
            right--;
        }
    }

    return ans;
}