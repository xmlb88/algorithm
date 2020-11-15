#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& poped) {
    int j = 0;
    stack<int> st;
    for (int num : pushed) {
        st.push(num);
        while (!st.empty() && j < poped.size() && st.top() == poped[j]) {
            st.pop();
            j++;
        }
    }
    return j == poped.size();
    // return st.empty();
}