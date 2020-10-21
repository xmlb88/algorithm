#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class CQueue{
public:
    stack<int> st1;
    stack<int> st2;

    CQueue() {

    }

    void appendTail(int value) {
        st1.push(value);
    }

    int deleteHead() {
        if (st1.empty() && st2.empty()) return -1;

        if (!st2.empty()) {
            int res = st2.top();
            st2.pop();
            return res;
        }

        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int res = st2.top();
        st2.pop();
        return res;
    }
};