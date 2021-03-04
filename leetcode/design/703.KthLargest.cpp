#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest{
private:
    priority_queue<int, vector<int>, greater<int>> q;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (auto& x : nums) {
            add(x);
        }
    }

    int add(int val) {
        q.push(val);
        if (q.size() > K) {
            q.pop();
        }
        return q.top();
    }
};