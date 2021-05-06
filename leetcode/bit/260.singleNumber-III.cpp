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

// review 2021��5��6��16:52:29
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
// �ȶ��������ֽ������������õ�2����ͬ���ֵ������������2���������Ϊ0
// ����������һλ(ѡ�����һλ1)���з���
// ���ڷֱ����õ����
vector<int> singleNumber(vector<int>& nums) {
    int x = 0;
    for (int num : nums) {
        x ^= num;
    }
    
    // ȡ���һλΪ1
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