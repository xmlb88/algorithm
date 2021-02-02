#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int equalSubstring(string s, string t, int maxCost) {
    int n = s.size();
    int left = 0, right = 0;
    int totalCost = 0;
    while (right < n) {
        totalCost += abs(s[right] - t[right]);
        right++;
        if (totalCost > maxCost) {
            totalCost -= abs(s[left] - t[left]);
            left++;
        }
    }
    return right - left;
}