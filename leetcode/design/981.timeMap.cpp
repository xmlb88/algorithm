#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> m;
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        m[key].emplace_back(value, timestamp);
    }

    string get(string key, int timestamp) {
        auto& vec = m[key];
        int n = vec.size();
        if (n == 0 || vec[0].second > timestamp) return "";
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (vec[mid].second <= timestamp) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return vec[right].first;
    }
};