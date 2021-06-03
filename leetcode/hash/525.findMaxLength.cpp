#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0;
    int max_length = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; j += 2) {
            int count_0 = 0, count_1 = 0;
            for (int k = i; k <= j; ++k) {
                if (nums[k] == 0) ++count_0;
                else ++count_1;
            }
            if (count_0 == count_1) {
                max_length = max(max_length, j - i + 1);
            }
        }
    }
    return max_length;
}


int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0;

    vector<int> num_0(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (nums[i - 1] == 0) num_0[i] = num_0[i - 1] + 1;
        else num_0[i] = num_0[i - 1];
    }

    int max_length = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; j += 2) {
            int len = j - i + 1;
            if (num_0[j + 1] - num_0[i] == len / 2) {
                max_length = max(max_length, len);
            }
        }
    }
    return max_length;
}

int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0;
    
    int max_length = 0;
    for (int i = 0; i < n - 1; ++i) {
        int count_0 = 0, count_1 = 0;
        for (int j = i; j < n; ++j) {
            if (nums[j] == 0) ++count_0;
            else ++count_1;

            if (count_0 == count_1) max_length = max(max_length, j - i + 1);
        }
    }
    return max_length;
}

int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0;

    unordered_map<int, int> m;
    m[0] = -1;
    int pre = 0, max_length = 0;
    for (int i = 0; i < n; ++i) {
        pre = nums[i] == 0 ? pre - 1 : pre + 1;
        if (m.find(pre) != m.end()) max_length = max(max_length, i - m[pre]);
        else m[pre] = i;
    }
    return max_length;
}