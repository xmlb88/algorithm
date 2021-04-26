#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int shipWithinDays(vector<int>& weights, int D) {
    int max_weight = 0, sum_weight = 0;
    for (auto w : weights) {
        max_weight = max(max_weight, w);
        sum_weight += w;
    }

    int l = max_weight, r = sum_weight;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int day = needDays(weights, mid);
        if (day > D) {
            l = mid + 1;
        } else r = mid - 1;
    }

    return l;
}

int needDays(vector<int>& weights, int w) {
    int day = 0;
    int sum = 0;
    for (auto weight : weights) {
        if (sum + weight > w) {
            sum = weight;
            day++;
        } else {
            sum += weight;
        }
    }
    day++;
    return day;
}

int check(vector<int>& weights, int k) {
    int day = 1, sum = 0;
    for (auot w : weights) {
        if (sum + w > k) {
            ++day;
            sum = w;
        } else sum += w;
    }
    return day;
}

int shipWithinDays(vector<int>& weights, int D) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(weights, mid) <= D) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}