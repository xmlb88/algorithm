#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) return i;
    }
    return arr.size() - 1;
}

int peakIndexInMountainArray(vector<int>& arr) {
    int left = 1, right = arr.size() - 1;
    while (left < right) {
        int mid = left + right >> 1;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid;
        } else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        } else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1]) {
            right = mid;
        }
    }
    return arr.size() - 1;
}

// 
int peakIndexInMountainArray(vector<int>& arr) {
    int lo = 0, hi = arr.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < arr[mid + 1]) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}