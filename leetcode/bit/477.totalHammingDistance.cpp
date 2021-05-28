#include <iostream>
#include <vector>
using namespace std;

int hamming(int a, int b) {
    int x = a ^ b;
    int count = 0;
    while (x) {
        x = x & (x - 1);
        ++count;
    }
    return count;
}

int totalHammingDistance(vector<int>& nums) {
    int total = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            total += hamming(nums[i], nums[j]);
        }
    }
    return total;
}

// int main() {
//     vector<int> nums = {1, 2, 3, 4};
//     cout << totalHammingDistance(nums) << endl;
// }

// 
// 0001 0010 0011 0100 2+1+2 + 1+2 + 3 = 11
// 0 + 3 + 4 + 4 
int totalHammingDistance(vector<int>& nums) {
    int total = 0, n = nums.size();
    for (int i = 0; i < 32; ++i) {
        int count = 0;
        for (int num : nums) {
            if (num & (1 << i)) ++count;
        }
        total += count * (n - count);
    }
    return total;
}

int totalHammingDistance(vector<int>& nums) {
    int res = 0, n = nums.size();
    for (int i = 0; i < 30; ++i) {
        int c = 0;
        for (int val : nums) {
            c += (val >> i) & 1;
        }
        res += c * (n - c);
    }
    return res;
}