#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


// nums = [1,12,-5,-6,50,3], k = 4
// ���ַ�
// TODO:
double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    double l = INT_MAX;
    double r = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] < l) {
            l = nums[i];
        }

        if (nums[i] > r) {
            r = nums[i];
        }
    }

    double mid = (l + r) * 0.5;
    double prevMid = 0.0;
    while (abs(prevMid - mid) > 1e-5) {
        if (Check(mid, nums, k)) {
            l = mid;
        } else {
            r = mid;
        }
        prevMid = mid;
        mid = (l + r) * 0.5;
    }

    return mid;
}

bool Check(double mid, const vector<int>& nums, int k) {
    // ��ǰ�ۼƵĺ�
    double sumj = 0;
    // ǰ׺�ۼƵĺ�(k��Ԫ��ǰ��)
    double sumi = 0;
    // �����ǰ׺�;���sumj - sumi
    // ��¼��С��sumi, 0��Ԫ��ʱ���ʼ��Ϊ0
    double minSumi = 0;

    int n = nums.size();
    for (int i = 0; i < k; ++i) {
        sumj += nums[i] - mid;
    }

    // ��һ��k�����������㣬�򷵻�true
    if (sumj >= 0) return true;

    for (int i = k; i < n; ++i) {
        sumj += nums[i] - mid;
        sumi += nums[i - k] - mid;
        minSumi = min(minSumi, sumi);
        if (sumj - minSumi >= 0) return true;
    }
    return false;
}