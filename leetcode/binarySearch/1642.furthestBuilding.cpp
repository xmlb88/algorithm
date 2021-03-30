#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

// own
// 大顶堆 + 贪心
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int> use_brick;
    int i = 0;
    while (i < heights.size()) {
        if (i == heights.size() - 1) return i;

        if (heights[i] >= heights[i + 1]) {
            ++i;
            continue;
        }

        int dis = heights[i + 1] - heights[i];
        if (bricks >= dis) {
            use_brick.push(dis);
            bricks -= dis;
            ++i;
            continue;
        }

        if (ladders > 0) {
            if ((use_brick.empty()) || (!use_brick.empty() && dis >= use_brick.top())) {
                --ladders;
                ++i;
                continue;
            } else {
                --ladders;
                bricks += use_brick.top() - dis;
                use_brick.pop();
                use_brick.push(dis);
                ++i;
                continue;
            }
        }
        return i;
    }
    return i;
}

int main() {
    vector<int> vec = {1,13,1,1,13,5,11,11};
    cout << furthestBuilding(vec, 10, 8) << endl;
}

// 二分
// https://leetcode-cn.com/problems/furthest-building-you-can-reach/solution/ba-ti-zi-yong-zai-he-gua-de-di-fang-shi-zhuan-tou-/
// 

bool check(vector<int>& heights, int bricks, int ladders, int target) {
    if (target == 0) return true;
    vector<int> differ(target);
    for (int i = 0; i < target; ++i) {
        differ[i] = heights[i + 1] - heights[i];
    }

    sort(differ.begin(), differ.end());
    for (int i = target - 1; i >= 0; i--) {
        if (differ[i] < 0) continue;
        if (ladders > 0) {
            ladders--;
            continue;
        } else if (bricks >= differ[i]) {
            bricks -= differ[i];
            continue;
        } else return false;
    }
    return true;
}

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int n = heights.size();
    int left = 0, right = n - 1;
    int res = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(heights, bricks, ladders, mid)) {
            res = mid;
            left = mid + 1;
        } else right = mid - 1;
    }
    return res;
}

// 最小堆 + 贪心
// https://leetcode-cn.com/problems/furthest-building-you-can-reach/solution/ke-yi-dao-da-de-zui-yuan-jian-zhu-by-zerotrac2/
// 

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int n = heights.size();
    priority_queue<int, vector<int>, greater<int>> q;   // 最小堆
    int sumH = 0;
    for (int i = 1; i < n; ++i) {
        int deltaH = heights[i] - heights[i - 1];
        if (deltaH > 0) {
            q.push(deltaH);
            if (q.size() > ladders) {
                sumH += q.top();
                q.pop();
            }
            if (sumH > bricks) {
                return i - 1;
            }
        }
    }
    return n - 1;
}