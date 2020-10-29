#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> findContinuousSequence(int target) {
    int left = 1, right = 1;
    int sum = 0;
    vector<vector<int>> res;

    while (left <= target / 2) {
        if (sum < target) {
            sum += right;
            right++;
        } else if (sum > target) {
            sum -= left;
            left++;
        } else if (sum == target) {
            vector<int> vec;
            for (int i = left; i < right; i++) {
                vec.push_back(i);
            }
            res.push_back(vec);
            sum -= left;
            left++;
        }
    }
    return res;
}

// try
vector<vector<int>> findContinuousSequence(int target) {
    int left = 1, right = 1;
    int sum = 0;
    vector<vector<int>> res;

    while (left <= target / 2) {
        while (sum < target) {
            sum += right;
            right++;
        }

        while (sum >= target) {
            if (sum == target) {
                vector<int> vec;
                for (int i = left; i < right; i++) {
                    vec.push_back(i);
                }
                res.push_back(vec);
            }
            sum -= left;
            left++;
        }
    }
    return res;
}