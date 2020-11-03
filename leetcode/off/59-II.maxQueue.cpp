#include <iostream>
#include <queue>
#include <deque>
using namespace std;

class MaxQueue {
public:
    queue<int> que;
    deque<int> deq;

    MaxQueue() {

    }
    
    int max_value() {
        if (deq.empty()) return -1;
        else return deq.front();
    }
    
    void push_back(int value) {
        que.push(value);
        while (!deq.empty() && deq.back() < value) deq.pop_back();
        deq.push_back(value);
    }
    
    int pop_front() {
        if (que.empty()) return -1;
        int value = que.front();
        que.pop();
        if (!deq.empty() && deq.front() == value) deq.pop_front();
        return value;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */