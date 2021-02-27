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


int equalSubstring(string s, string t, int maxCost) {
    int left = 0, right = 0;
    int sumCost = 0;
    int len = 0;
    while (right < s.size()) {
        sumCost += abs(s[right] - t[right]);
        right++;

        if (sumCost > maxCost) {
            sumCost -= abs(s[left] - t[left]);
            left++;
        }
    }
    return right - left;
}

int equalSubstring(string s, string t, int maxCost) {
    int left = 0, right = 0;
    int cost = 0;
    while (right < s.size()) {
        cost += abs(s[right] - t[right]);
        right++;

        if (cost > maxCost) {
            cost -= abs(s[left] - t[left]);
            left++;
        }
    }
    return right - left;
}


int equalSubstring(string s, string t, int maxCost) {
    int left = 0, right = 0;
    int cost = 0;
    while (right < s.size()) {
        cost += abs(s[right] - t[right]);
        right++;

        if (cost > maxCost) {
            cost -= abs(s[left] - t[left]);
            left++;
        }
    }
    return right - left;
}