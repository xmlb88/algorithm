#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!st2.empty()) {
            int res = st2.top();
            st2.pop();
            return res;
        } else {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            int res = st2.top();
            st2.pop();
            return res;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if (!st2.empty()) {
            return st2.top();
        } else {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// review 2021Äê3ÔÂ5ÈÕ
class MyQueue{
private:
    stack<int> stackIn, stackOut;
public:
    MyQueue() {}
    void push(int x) {
        stackIn.push(x);
    }

    void trans() {
        while (!stackIn.empty()) {
            stackOut.push(stackIn.top());
            stackIn.pop();
        }
    }

    int pop() {
        if (stackOut.empty()) trans();
        int x = stackOut.top();
        stackOut.pop();
        return x;
    }

    int peek() {
        if (stackOut.empty()) trans();
        int x = stackOut.top();
        return x;
    }

    bool empty() {
        return stackIn.empty() && stackOut.empty();
    }
};