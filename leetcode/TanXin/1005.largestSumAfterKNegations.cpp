#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
using namespace std;


// TODO:
int largestSumAfterKNegations(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> q(nums.begin(), nums.end());
    while (k--) {
        int num = q.top();
        q.pop();
        q.push(-num);
    }

    int sum = 0;
    while (!q.empty()) {
        sum += q.top();
        q.pop();
    }
    return sum;
}