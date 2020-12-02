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
    
    int getMin() {
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

// µ¥Õ»
class MinStack {
public:
    stack<int> st;
    int min_num = INT_MAX;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (x <= min_num) {
            st.push(min_num);
            min_num = x;
        }
        st.push(x);
    }
    
    void pop() {
        int n = st.top();
        st.pop();
        if (n == min_num) {
            min_num = st.top();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_num;
    }
};

// µ¥Õ» push²îÖµ
class MinStack {
public:
    /** initialize your data structure here. */
    stack<long> st;
    long min_num;
    MinStack() {

    }
    
    void push(int x) {
        if (st.empty()) {
            min_num = x;
            st.push(0);
        } else {
            st.push(x - min_num);
            if (x < min_num) {
                min_num = x;
            }
        }
    }
    
    void pop() {
        long pop = st.top();
        st.pop();
        if (pop < 0) {
            min_num -= pop;
        }
    }
    
    int top() {
        long top_num = st.top();
        if (top_num > 0) {
            return (int)(top_num + min_num);
        } else {
            return (int)min_num;
        }
    }
    
    int getMin() {
        return (int)min_num;
    }
};

// -2 0 -3
// 0 min -2
// 2 min -2
// -1 min -3