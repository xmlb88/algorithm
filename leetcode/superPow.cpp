#include<iostream>
#include<vector>
using namespace std;


// 计算a 的k 次方的结果

int mypow(int a, int k);

// 解决数组问题
int superPow(int a, vector<int>& b) {
    // 递归的base case
    if (b.empty()) return 1;

    // 取出最后一个数
    int last = b.back();
    b.pop_back();

    // 将原问题化简，缩小规模递归求解
    int part1 = mypow(a, last);
    int part2 = mypow(superPow(a, b), 10);

    // 合并出结果
    return part1 * part2;
}

// 处理mod运算
// (a * b) % k = (a % k)(b % k) % k
int base = 1337;
// 计算a的k次方然后与base求模的结果
int mypow(int a, int k) {
    // 对因子求模
    a %= base;
    int res = 1;
    for (int i = 0; i < k; i++) {
        // 乘法可能会溢出
        res *= a;
        // 对乘法结果求模
        res %= base;
    }

    return res;
}

int superPow(int a, vector<int>& b) {
    if (b.empty()) return 1;
    int last = b.back();
    b.pop_back();

    int part1 = mypow(a, last);
    int part2 = mypow(superPow(a, b), 10);

    // 每次乘法取模
    return (part1 * part2) % base;
}

