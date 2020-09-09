#include<iostream>
#include<vector>
using namespace std;

int minEatingSpeed(vector<int>& piles, int H) {
    // piles数组的最大值
    int max = getMax(piles);
    for (int speed = 1; speed < max; speed++) {
        // 以speed是否能在H小时内吃完香蕉
        if (canFinish(piles, speed, H)) {
            return speed;
        }
    }

    return max;
}

// for循环改为搜索左侧边界的二分查找

int minEatingSpeed(vector<int>& piles, int H) {
    // 搜索左侧边界的算法
    int left = 1, right = getMax(piles) + 1;
    while (left < right) {
        // 防止溢出
        int mid = left + (right - left) / 2;
        if (canFinish(piles, mid, H)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

bool canFinish(vector<int>& piles, int speed, int H) {
    int time = 0;
    for (int n : piles) {
        time += timeOf(n, speed);
    }

    return time <= H;
}

int timeOf(int n, int speed) {
    return (n / speed) + ((n % speed > 0)? 1 : 0);
}

int getMax(vector<int>& piles) {
    int m = 0;
    for (int n : piles) {
        m = max(m, n);
    }

    return m;
}