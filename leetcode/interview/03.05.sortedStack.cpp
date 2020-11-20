#include <iostream>
#include <stack>
using namespace std;

class SortedStack {
public:
    stack<int> st1;
    stack<int> st2;
    SortedStack() {

    }
    
    void push(int val) {
        while (!st1.empty() && st1.top() < val) {
            st2.push(st1.top());
            st1.pop();
        }

        while (!st2.empty() && st2.top() > val) {
            st1.push(st2.top());
            st2.pop();
        }

        st1.push(val);
    }

    void sort() {
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    void pop() {
        sort();
        if (!st1.empty()) st1.pop();
    }
    
    int peek() {
        sort();
        return st1.empty() ? -1 : st1.top();
    }
    
    bool isEmpty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */