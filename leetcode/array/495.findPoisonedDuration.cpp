#include <iostream>
#include <vector>
using namespace std;

// think too much
int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int n = timeSeries.size();
    if (n == 0) return 0;
    vector<pair<int, int>> time;
    for (auto series : timeSeries) {
        time.push_back({series, series + duration - 1});
    }

    vector<pair<int, int>> complex_time;
    for (int i = 0; i < n; i++) {
        if (complex_time.empty()) {
            complex_time.push_back(time[i]);
            continue;
        }
        auto time_kv = complex_time.back();
        if (time_kv.second >= time[i].first) {
            complex_time.pop_back();
            complex_time.push_back({time_kv.first, time[i].second});
        } else {
            complex_time.push_back(time[i]);
        }
    }

    int res = 0;
    for (auto kv : complex_time) {
        res += kv.second - kv.first + 1;
    }
    return res;
}

// Ò»´Î±éÀú
int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int n = timeSeries.size();
    if (n == 0) return 0;

    int total = 0;
    for (int i = 0; i < n - 1; i++) {
        total += min(timeSeries[i + 1] - timeSeries[i], duration);
    }
    return total + duration;
}