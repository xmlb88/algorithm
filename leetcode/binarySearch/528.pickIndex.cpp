#include <iostream>
#include <vector>
#include <random>
using namespace std;

class Solution {
public:
    vector<int> preSum;
    int total = 0;

    // c++11 random integer generation
    mt19937 rng{random_device{} ()};
    uniform_int_distribution<int> uni;

    Solution(vector<int>& w) {
        for (int x : w) {
            total += x;
            preSum.push_back(total);
        }
        uni = uniform_int_distribution<int> {0, total - 1};
    }
    
    int pickIndex() {
        int targ = uni(rng);
        int left = 0, right = preSum.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (targ >= preSum[mid]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

class Solution {
public:
    vector<int> preSum;
    int total = 0;
    Solution(vector<int>& w) {
        for (int x : w) {
            total += x;
            preSum.push_back(total);
        }
    }
    
    int pickIndex() {
        srand(time(0));
        int target = rand() % total + 1;
        int left = 0, right = preSum.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target >= preSum[mid]) {
                left = mid + 1;
            } else right = mid;
        }
        return left;
    }
};


class Solution {
public:
    vector<int> preSum;
    int total = 0;
    Solution(vector<int>& w) {
        for (int x : w) {
            total += x;
            preSum.push_back(total);
        }
    }
    
    int pickIndex() {
        // srand(time(0));
        int target = rand() % total + 1;
        return lower_bound(preSum.begin(), preSum.end(), target) - preSum.begin();
    }
};


class Solution {
public:
    vector<int> preSum;
    int total = 0;

    mt19937 rng{random_device{} ()};
    uniform_int_distribution<int> uni;

    Solution(vector<int>& w) {
        for (int x : w) {
            total += x;
            preSum.push_back(total);
        }

        uni = uniform_int_distribution<int> {1, total};
    }

    int pickIndex() {
        int target = uni(rng);
        return lower_bound(preSum.begin(), preSum.end(), target) - preSum.begin();
    }
};