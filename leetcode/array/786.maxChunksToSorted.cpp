#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// TODO:
int maxChunksToSorted(vector<int>& arr) {
    stack<int> st;
    for (int num : arr) {
        if (!st.empty() && num < st.top()) {
            int head = st.top();
            st.pop();
            while (!st.empty() && num < st.top()) st.pop();
            st.push(head);
        } else {
            st.push(num);
        }
    }
    return st.size();
}