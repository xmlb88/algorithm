#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = nums1.size() - 1;
    m--;
    n--;
    while (n >= 0) {
        while (m >= 0 && nums1[m] > nums2[n]) {
            nums1[i--] = nums1[m--];
        }
        nums1[i--] = nums2[n--];
    }
}