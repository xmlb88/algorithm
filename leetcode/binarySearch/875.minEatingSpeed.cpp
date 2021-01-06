#include <iostream>
#include <vector>
using namespace std;

int minEatingSpeed(vector<int>& piles, int H) {
    int l = 1, r = *(max_element(piles.begin(), piles.end()));
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int hour = needHours(piles, mid);
        if (hour > H) l = mid +1;
        else r = mid - 1;
    }

    return l;
}

int needHours(vector<int>& piles, int speed) {
    int hour = 0;
    for (auto amount : piles) {
        hour += amount / speed;
        if (amount % speed) hour++;
    }
    return hour;
}