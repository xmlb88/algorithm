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

// review 2021年3月5日
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

// review 2021年5月14日09:36:50
class MyQueue {
public:
    stack<int> st_in, st_out;
    MyQueue() {

    }

    void push(int x) {
        st_in.push(x);
    }

    void from_in_to_out() {
        if (st_out.empty()) {
            while (!st_in.empty()) {
                st_out.push(st_in.top());
                st_in.pop();
            }
        }
    }

    int pop() {
        from_in_to_out();
        int res = st_out.top();
        st_out.pop();
        return res;
    }

    int peek() {
        from_in_to_out();
        return st_out.top();
    }

    bool empty() {
        return st_in.empty() && st_out.empty();
    }

};