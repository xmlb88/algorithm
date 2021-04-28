#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool judgeSquareSum(int c) {
    for (int i = 0; i <= c / 2; ++i) {
        for (int j = 0; j <= c; ++j) {
            long long x = i;
            long long y = j;
            if (x * x + y * y == c) return true;
            else if (x * x + y * y > c) break;
        }
    }
    return false;
}


bool judgeSquareSum(int c) {
    long long i = 0, j = (int)sqrt(c);
    while (i <= j) {
        long long res = i * i + j * j;
        if (res == c) return true;
        
        if (res < c) i++;
        else if (res > c) j--;
    }
    return false;
}


// https://leetcode-cn.com/problems/sum-of-square-numbers/solution/ping-fang-shu-zhi-he-by-leetcode-solutio-8ydl/
// 

bool judgeSquareSum(int c) {
    for (long a = 0; a * a <= c; ++a) {
        double b = sqrt(c - a * a);
        if (b == int(b)) {
            return true;
        }
    }
    return false;
}


bool judgeSquareSum(int c) {
    long left = 0;
    long right = (int)sqrt(c);
    while (left <= right) {
        long sum = left * left + right * right;
        if (sum == c) return true;
        else if (sum > c) --right;
        else ++left;
    }
    return false;
}

// 费马平方和
bool judgeSquareSum(int c) {
    for (int base = 2; base * base <= c; ++base) {
        if (c % base != 0) continue;

        int exp = 0;
        while (c % base == 0) {
            c /= base;
            exp++;
        }

        if (base % 4 == 3 && exp % 2 != 0) return false;
    }
    return c % 4 != 3;
}