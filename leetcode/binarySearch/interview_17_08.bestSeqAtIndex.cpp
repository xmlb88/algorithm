#include <iostream>
#include <vector>
using namespace std;

int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
    int n = height.size();
    vector<pair<int, int>> people;
    for (int i = 0; i < n; ++i) {
        people.emplace_back(height[i], weight[i]);
    }

    sort(people.begin(), people.end(), [] (const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    });

    vector<int> dp(n, 1);
    int max_level = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (people[i].second > people[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_level = max(max_level, dp[i]);
    }
    return max_level;
}

// 二分
int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
    int n = height.size();
    vector<pair<int, int>> person;
    for (int i = 0; i < n; ++i) {
        person.emplace_back(height[i], weight[i]);
    }

    sort(person.begin(), person.end(), [] (const pair<int, int>& a, const pair<int, int>& b) {
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    });

    vector<int> tail;
    tail.push_back(person[0].second);
    for (int i = 1; i < n; ++i) {
        if (person[i].second > tail.back()) {
            tail.push_back(person[i].second);
        } else {
            int left = 0, right = tail.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (tail[mid] < person[i].second) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            tail[left] = person[i].second;
        }
    }
    return tail.size();
}

// 二分使用 lower_bound
int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
    int n = height.size();
    vector<pair<int, int>> person;
    for (int i = 0; i < n; ++i) {
        person.emplace_back(height[i], weight[i]);
    }

    sort(person.begin(), person.end(), [] (const pair<int, int>& a, const pair<int, int>& b) {
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    });

    vector<int> tail;
    for (const auto &[h, w] : person) {
        auto p = lower_bound(tail.begin(), tail.end(), w);
        if (p == tail.end()) tail.push_back(w);
        else *p = w;
    }
    return tail.size();
}