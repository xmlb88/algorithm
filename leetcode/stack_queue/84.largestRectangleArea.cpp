#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// violence
// 枚举宽
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    if (n == 0) return 0;
    int maxArea = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int area = (j - i + 1) * minHeights(heights, i, j);
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

int minHeights(vector<int>& heights, int i, int j) {
    if (i == j) return heights[i];
    int minheight = INT_MAX;
    for (int index = i; index <= j; index++) {
        minheight = min(minheight, heights[index]);
    }
    return minheight;
}

// violence
// 枚举高
int largestRectangleArea(vector<int>& heights) {
    int maxans = 0;
    int n = heights.size();
    if (n == 0) return 0;
    for (int mid = 0; mid < n; mid++) {
        int height = heights[mid];
        int left = mid, right = mid;
        while (left >= 1 && heights[left - 1] >= height) left--;
        while (right <= n - 2 && heights[right + 1] >= height) right++;
        maxans = max(maxans, height * (right - left + 1));
    }
    return maxans;
}

// 单调栈
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    if (n == 0) return 0;
    vector<int> left(n), right(n);

    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    st = stack<int> ();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    }
    return ans;
}

// 单调栈 一次遍历
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    if (n == 0) return 0;
    vector<int> left(n), right(n, n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            right[st.top()] = i;
            st.pop();
        }

        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    }
    return ans;
}