#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> q(stones.begin(), stones.end());
    while (q.size() > 1) {
        int st1 = q.top();
        q.pop();
        int st2 = q.top();
        q.pop();
        if (st1 - st2 > 0) {
            q.push(st1 - st2);
        }
    }

    return q.empty() ? 0 : q.top();
}