#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num_set;
    for (const int& num : nums) {
        num_set.insert(num);
    }

    int longestStreak = 0;

    for (const int& num : num_set) {
        if (!num_set.count(num - 1)) {
            int currentNum = num;
            int currentStreak = 1;

            while (num_set.count(currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}


// https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/zui-chang-lian-xu-xu-lie-by-leetcode-solution/
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num_set;
    for (const int& num : nums) {
        num_set.insert(num);
    }

    int longestStreak = 0;

    for (const int& num : num_set) {
        if (!num_set.count(num - 1)) {
            int currentNum = num;
            int currentStreak = 1;

            while (num_set.count(currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}

// union_find

class unionFind {
private:
    vector<int> f, rank;
    int maxSize = 1;
public:
    unionFind(int n) : f(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
    }

    int find(int x) {
        if (f[x] != x) {
            f[x] = find(f[x]);
        }
        return f[x];
    }

    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        f[fy] = fx;
        rank[fx] += rank[fy];
        maxSize = max(maxSize, max(rank[fx], rank[fy]));
    }

    int getMaxSize() {
        return maxSize;
    }
};

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> m;
    unionFind uf(n);
    for (int i = 0; i < n; ++i) {
        m[nums[i] = i];
    }

    for (int i = 0; i < n; ++i) {
        if (m.find(nums[i] + 1) != m.end()) {
            uf.merge(i, m[nums[i] + 1]);
        }
    }
    return uf.getMaxSize();
}