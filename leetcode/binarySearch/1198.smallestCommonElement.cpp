#include <iostream>
#include <vector>
using namespace std;


// 统计元素出现次数
// https://leetcode-cn.com/problems/find-smallest-common-element-in-all-rows/solution/zhao-chu-suo-you-xing-zhong-zui-xiao-gong-gong-yua/
//

int smallestCommonElement(vector<vector<int>>& mat) {
    vector<int> count(10001, 0);
    int n = mat.size(), m = mat[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ++count[mat[i][j]];
        }
    }

    for (int k = 1; k <= 10000; ++k) {
        if (count[k] == n) {
            return k;
        }
    }
    return -1;
}

// 改进
int smallestCommonElement(vector<vector<int>>& mat) {
    vector<int> count(10001, 0);
    int n = mat.size(), m = mat[0].size();
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (++count[mat[i][j]] == n) {
                return mat[i][j];
            }
        }
    }
    return -1;
}

// 二分搜索

bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return true;
        else if (nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return false;
}

int smallestCommonElement(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    for (int j = 0; j < m; ++j) {
        bool found = true;
        for (int i = 1; i < n && found; ++i) {
            found = search(mat[i], mat[0][j]);
        }

        if (found) return mat[0][j];
    }
    return -1;
}

// 改进
int smallestCommonElement(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<int> pos(n);
    for (int j = 0; j < m; ++j) {
        bool found = true;
        for (int i = 1; i < n && found; ++i) {
            pos[i] = lower_bound(begin(mat[i]), end(mat[i]), mat[0][j]) - begin(mat[i]);
            if (pos[i] >= m) return -1;
            found = mat[i][pos[i]] == mat[0][j];
        }
        
        if (found) return mat[0][j];
    }
    return -1;
}

// 行位置，每行指针
int smallestCommonElement(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int cur_max = 0, cnt = 0;
    vector<int> pos(n);
    while (true) {
        for (int i = 0; i < n; ++i) {
            pos[i] = lower_bound(begin(mat[i]) + pos[i], end(mat[i]), cur_max) - begin(mat[i]);
            if (pos[i] >= m) return -1;

            if (cur_max == mat[i][pos[i]]) {
                if (++cnt == n) return cur_max;
            } else {
                cnt = 1;
            }
            cur_max = mat[i][pos[i]];
        }
    }
    return -1;
}

// review own
int smallestCommonElement(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<int> pos(n);
    int cur_max = 0, cnt = 0;
    while (true) {
        for (int i = 0; i < n; ++i) {
            pos[i] = lower_bound(begin(mat[i]), end(mat[i]), cur_max) - begin(mat[i]);
            if (pos[i] >= m) return -1;

            if (cur_max == mat[i][pos[i]]) {
                if (++cnt == n) return cur_max;
            } else {
                cur_max = mat[i][pos[i]];
                cnt = 1;
            }
        }
    }
    return -1;
}