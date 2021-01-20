#include <iostream>
#include <vector>
using namespace std;

int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return max(nums[0] * nums[1] * nums[nums.size() - 1], nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]);
}

int maximumProduct(vector<int>& nums) {
    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    for (int n : nums) {
        if (n <= min1) {
            min2 = min1;
            min1 = n;
        } else if (n <= min2) {
            min2 = n;
        }

        if (n >= max1) {
            max3 = max2;
            max2 = max1;
            max1 = n;
        } else if (n >= max2) {
            max3 = max2;
            max2 = n;
        } else if (n >= max3) {
            max3 = n;
        }
    }
    return max(min1 * min2 * max1, max1 * max2 *max3);
}

// review 2021Äê1ÔÂ20ÈÕ09:47:39
int maximumProduct(vector<int>& nums) {
    int res = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                res = max(res, nums[i] * nums[j] * nums[k]);
            }
        }
    }
    return res;
}

// -5 -4 -3 -2 -1
int maximumProduct(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int num1 = nums[0] * nums[1] * nums[n - 1];
    int num2 = nums[n - 1] * nums[n - 2] * nums[n - 3];
    return max(num1, num2);
}

int maximumProduct(vector<int>& nums) {
    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

    for (int& num : nums) {
        if (num < min1) {
            min2 = min1; min1 = num;
        } else if (num < min2) {
            min2 = num;
        }

        if (num > max1) {
            max3 = max2; max2 = max1; max1 = num;
        } else if (num > max2) {
            max3 = max2; max2 = num;
        } else if (num > max3) {
            max3 = num;
        }
    }

    return max(min1 * min2 * max1, max1 * max2 * max3);
}