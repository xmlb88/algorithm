#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int x = 0;
    for (int num : nums) {
        x ^= num;
    }

    int div = 1;
    while ((div & x) == 0) {
        div <<= 1;
    }

    int a = 0, b = 0;
    for (int num : nums) {
        if ((div & num) == 0) a ^= num;
        else b ^= num;
    }

    return {a, b};
}

// review 2021年5月6日16:52:29
vector<int> singleNumber(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int num : nums) {
        m[num]++;
    }

    vector<int> res;
    for (auto& [_, c] : m) {
        if (c == 1) res.push_back(_);
    }
    return res;
}

// https://leetcode-cn.com/problems/single-number-iii/solution/zhi-chu-xian-yi-ci-de-shu-zi-iii-by-leet-4i8e/
// 先对所有数字进行异或操作，得到2个不同数字的异或结果，出现2次数字异或为0
// 根据数字任一位(选择最后一位1)进行分组
// 组内分别异或得到结果
vector<int> singleNumber(vector<int>& nums) {
    int x = 0;
    for (int num : nums) {
        x ^= num;
    }
    
    // 取最后一位为1
    // int div = 1;
    // while ((div & x) == 0) {
    //     div <<= 1;
    // }
    int div;
    if (x == INT_MIN) div = 1;
    // else div = x & (-x);
    else div = x - (x & (x - 1));

    int a = 0, b = 0;
    for (int num : nums) {
        if (num & div) {
            a ^= num;
        } else {
            b ^= num;
        }
    }
    return {a, b};
}