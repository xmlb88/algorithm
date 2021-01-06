#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();

    int maxArea = 0;
    vector<vector<int>> dp(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1') {
                dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;

                int width = dp[i][j];

                for (int k = i; k >= 0; k--) {
                    width = min(width, dp[k][j]);
                    maxArea = max(maxArea, width * (i - k + 1));
                }
            }
        }
    }
    return maxArea;
}

// ջ
int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();
    for ()
}

int maxArea(vector<int>& heights) {
    int n = heights.size();
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

    int area = 0;
    for (int i = 0; i < n; i++) {
        area = max(area, heights[i] * (right[i] - left[i] - 1));
    }

    return area;
}