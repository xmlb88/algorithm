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
