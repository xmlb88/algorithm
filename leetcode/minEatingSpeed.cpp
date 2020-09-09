#include<iostream>
#include<vector>
using namespace std;

int minEatingSpeed(vector<int>& piles, int H) {
    // piles��������ֵ
    int max = getMax(piles);
    for (int speed = 1; speed < max; speed++) {
        // ��speed�Ƿ�����HСʱ�ڳ����㽶
        if (canFinish(piles, speed, H)) {
            return speed;
        }
    }

    return max;
}

// forѭ����Ϊ�������߽�Ķ��ֲ���

int minEatingSpeed(vector<int>& piles, int H) {
    // �������߽���㷨
    int left = 1, right = getMax(piles) + 1;
    while (left < right) {
        // ��ֹ���
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