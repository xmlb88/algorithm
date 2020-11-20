#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> min_element;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        s.push(x);
        if (min_element.empty()) min_element.push(x);
        else {
            int min_number = min_element.top();
            if (x < min_number) min_element.push(x);
            else min_element.push(min_number);
        }
    }
    
    void pop() {
        s.pop();
        min_element.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_element.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */