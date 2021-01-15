#include <iostream>
#include <vector>
using namespace std;

int countBit(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

vector<int> countBits(int num) {
    vector<int> res(num + 1);
    for (int i = 0; i <= num; i++) {
        res[i] = countBit(i);
    }
    return res;
}

// 动态规划 + 最低有效位
vector<int> countBits(int num) {
    vector<int> res(num + 1);
    for (int i = 0; i <= num; i++) {
        res[i] = res[i >> 1] + (i & 1);
    }
    return res;
}

// 动态规划 + 最后设置位
// 利用最后一个位1 i & (i - 1) 消除后得到之前计算了的结果 + 1

vector<int> countBits(int num) {
    vector<int> res(num + 1);
    for (int i = 1; i <= num; i++) {
        res[i] = res[i & (i - 1)] + 1;
    }
    return res;
}

// 动态规划 + 最高有效位
// 利用以前计算过的数 + 1 > 得到现在结果，最高位
// P(x+b)=P(x)+1,b=2^m >x

// review 2021年1月15日10:46:19
// bitset
vector<int> countBits(int num) {
    vector<int> res;
    for (int i = 0; i <= num; i++) {
        bitset<32> bs(i);
        res.push_back(bs.count());
    }
    return res;
}

// pop count
vector<int> countBits(int num) {
    vector<int> res;
    for (int i = 0; i <= num; i++) {
        res.push_back(popcount(i));
    }
    return res;
}

int popcount(int n) {
    int count = 0;
    while (n) {
        count++;
        n &= n - 1;
    }
    return count;
}
// num = 5, i = 0, b = 1
// res[1] = res[0] + 1 = 1; i = 1
// i = 0, b = 2;
// res[2] = res[0] + 1 = 1; i = 1;
// res[3] = res[1] + 1 = 2; i = 2;
// i = 0, b = 4;
// res[4] = res[0] + 1 = 1; i = 1;
// res[5] = res[1] + 1 = 2; i = 2;
// res[6] = res[2] + 1 = 2; i = 3;
// res[7] = res[3] + 1 = 3; i = 4;
// dp + 最高有效位

vector<int> countBits(int num) {
    vector<int> res(num + 1);
    int i = 0, b = 1;
    while (b <= num) {
        while (i < b && i + b <= num) {
            res[i + b] = res[i] + 1;
            i++;
        }
        i = 0;
        b <<= 1;
    }
    return res;
}

// dp + 最低有效位
vector<int> countBits(int num) {
    vector<int> res(num + 1);
    for (int i = 1; i <= num; i++) {
        res[i] = res[i >> 1] + (i & 1);
    }
    return res;
}

// dp + 最后设置位
vector<int> countBits(int num) {
    vector<int> res(num + 1);
    for (int i = 1; i <= num; i++) {
        res[i] = res[i & (i - 1)] + 1;
    }
    return res;
}

// dp + 奇偶性
vector<int> countBits(int num) {
    vector<int> res(num + 1);
    for (int i = 1; i <= num; i++) {
        if (i & 1) res[i] = res[i - 1] + 1;
        else res[i] = res[i >> 1];
    }
    return res;
}