#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;

    void addNum(int num) {
        lo.push(num);

        hi.push(lo.top());
        lo.pop();

        if (hi.size() > lo.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        return lo.size() > hi.size() ? (double) lo.top() : (hi.top() + lo.top()) / 2.0;
    }
};