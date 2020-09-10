#include<iostream>
#include<vector>
using namespace std;

int sumOfWights;
int maxOfWights;

// int shipWithinDays(vector<int>& wights, int D) {
//     getMaxAndSum(wights);

//     for (int i = maxOfWights; i < sumOfWights; i++) {
//         if (canFinish(wights, i, D)) return i;
//     }

//     return sumOfWights;
// }

// 转化二分搜索
int shipWithinDays(vector<int>& wights, int D) {
    getMaxAndSum(wights);

    int left = maxOfWights, right = sumOfWights;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canFinish(wights, mid, D)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

void getMaxAndSum(vector<int>& wights) {
    sumOfWights = 0;
    maxOfWights = 0;

    for (int w : wights) {
        sumOfWights += w;
        maxOfWights = max(maxOfWights, w);
    }
}

bool canFinish(vector<int>& wights, int canWight, int D) {
    int sum = 0;
    int day = 0;

    for (int w : wights) {
        sum += w;
        if (sum > canWight) {
            sum = w;
            day++;
        }
    }
    return day + 1 <= D;

    // int i = 0;
    // for (int day = 0; day < D; day++) {
    //     int maxCap = cap;
    //     while ((maxCap -= wights[i]) >= 0) {
    //         i++;
    //         if (i == wights.size()) return true;
    //     }
    // }

    // return false;
}