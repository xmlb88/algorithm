#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// TLE 54/60
// int numSubarraysWithSum(vector<int>& nums, int goal) {
//     int n = nums.size();
//     vector<int> preSum(n + 1, 0);
//     for (int i = 0; i < n; ++i) {
//         preSum[i + 1] = preSum[i] + nums[i];
//     }

//     int count = 0;
//     for (int i = 0; i < n; ++i) {
//         for (int j = i; j < n; ++j) {
//             if (preSum[j + 1] - preSum[i] == goal) ++count;
//         }
//     }

//     return count;
// }

// »¬¶¯´°¿Ú
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    int count = 0, sum1 = 0, sum2 = 0;
    int left1 = 0, left2 = 0, right = 0;
    while (right < n) {
        sum1 += nums[right];
        while (left1 <= right && sum1 > goal) {
            sum1 -= nums[left1];
            ++left1;
        }

        sum2 += nums[right];
        while (left2 <= right && sum2 >= goal) {
            sum2 -= nums[left2];
            ++left2;
        }

        count += left2 - left1;
        ++right;
    }
    return count;
}

// ¹þÏ£±í :(
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    unordered_map<int, int> m;
    int sum = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        ++m[sum];
        sum += nums[i];
        count += m[sum - goal];
    }
    return count;
}

int main() {
    vector<int> nums = {0, 0, 0, 0, 0};
    cout << numSubarraysWithSum(nums, 0) << endl;
}