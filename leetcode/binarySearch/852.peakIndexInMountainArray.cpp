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

int peakIndexInMountainArray(vector<int>& arr) {
    int i = 0;
    while (i < arr.size() - 1 && arr[i] < arr[i + 1]) ++i;
    return i;
}

int peakIndexInMountainArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < arr[mid + 1]) left = mid + 1;
        else right = mid;
    }
    return left;
}