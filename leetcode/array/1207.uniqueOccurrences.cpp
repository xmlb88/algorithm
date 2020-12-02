#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> cnt;
    for (int num : arr) {
        cnt[num]++;
    }

    unordered_set<int> times;
    for (auto it : cnt) {
        if (times.count(it -> second)) return false;
        times.insert(it -> second);
    }
    return true;
}