#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// hash
int singleNumber(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int num : nums) {
        m[num]++;
    }

    for (auto& [_, c] : m) {
        if (c == 1) return _;
    }
    return -1;
}

// 依次计算每一个二进制位的个数
int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < 32; ++i) {
        int total = 0;
        for (int num : nums) {
            total += ((num >> i) & 1);
        }
        if (total % 3) {
            res |= (1 << i);
        }
    }
    return res;
}

// 依次计算每一个二进制位
// int singleNumber(vector<int>& nums) {
//     int res = 0;
//     for (int i = 0; i < 32; ++i) {
//         int total = 0;
//         for (int num : nums) {
//             total += ((num >> i) & 1);
//         }

//         if (total % 3) {
//             res |= (1 << i);
//         }
//     }
//     return res;
// }


// https://leetcode-cn.com/problems/single-number-ii/solution/zhi-chu-xian-yi-ci-de-shu-zi-ii-by-leetc-23t6/
// 
int singleNumber(vector<int>& nums) {
    int a = 0, b = 0;
    for (int num : nums) {
        int temp_a = (~a & b & num) | (a & ~b & ~num);
        int temp_b = ~a & (b ^ num);
        a = temp_a;
        b = temp_b;
    }
    return b;
}

int singleNumber(vector<int>& nums) {
    int a = 0, b = 0;
    for (int num : nums) {
        b = ~a & (b ^ num);
        a = ~b & (a ^ num);
    }
    return b;
}