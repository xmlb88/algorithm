#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> minSt;
    MinStack() {

    }
    
    void push(int x) {
        if (st.empty() && minSt.empty()) {
            st.push(x);
            minSt.push(x);
        } else {
            st.push(x);
            minSt.push(min(x, minSt.top()));
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int min() {
        return minSt.top();
    }
};

/**
 * Your minStStack object will be instantiated and called as such:
 * minStStack* obj = new minStStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getminSt();
 */