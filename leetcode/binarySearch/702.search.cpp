#include <iostream>
#include <vector>
using namespace std;

const int out_of_range = 2147483647;
int search(const ArrayReader& reader, int target) {
    int left = 0, right = 1e9;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int res = reader.get(mid);
        if (res == out_of_range || res > target) {
            right = mid - 1;
        } else if (res == target) {
            return mid;
        } else if (res < target) {
            left = mid + 1;
        }
    }
    return -1;
}

// ÏÈËÑË÷±ß½ç
int search(const ArrayReader& reader, int target) {
    if (reader.get(0) == target) return 0;
    
    int left = 0, right = 1;
    while (reader.get(right) < target) {
        left = right;
        right <<= 1;
    }

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int num = reader.get(mid);

        if (num == target) return mid;
        else if (num > target) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}