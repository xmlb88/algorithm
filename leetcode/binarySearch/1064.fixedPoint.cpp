#include <iostream>
#include <vector>
using namespace std;

int fixedPoint(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return -1;

    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < 0) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    if (left == n) return -1;

    for (int i = left; i < n; ++i) {
        if (arr[i] == i) return i;
    }
    return -1;
}

// 二分搜索，上面有问题
int fixedPoint(vector<int>& arr) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == mid) right = mid;
        else if (arr[mid] > mid) right = mid;
        else if (arr[mid] < mid) left = mid + 1;
    }
    if (left == arr.size()) return -1;
    return arr[left] == left ? left : -1;
}

