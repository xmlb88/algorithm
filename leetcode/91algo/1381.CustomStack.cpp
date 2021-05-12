#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

// 3 1 3 4 
// 103 101 103 104
// 203 201 103 104
class CustomStack {
public:
    int max_size;
    vector<int> st;
    CustomStack(int maxSize) {
        max_size = maxSize;
    }
    
    void push(int x) {
        if (st.size() >= max_size) {
            return;
        }
        st.push_back(x);
    }
    
    int pop() {
        if (!st.empty()) {
            int temp = st.back();
            st.pop_back();
            return temp;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        k = min(k, (int)st.size());
        for (int i = 0; i < k; ++i) {
            st[i] += val;
        }
    }
};

// ÓÅ»¯
class CustomStack {
public:
    vector<int> st, add;
    int idx = -1;
    CustomStack(int maxSize) {
        st.resize(maxSize, 0);
        add.resize(maxSize, 0);
    }
    
    void push(int x) {
        if (idx == st.size() - 1) return;
        st[++idx] = x;
    }
    
    int pop() {
        if (idx == -1) return -1;
        int ret = st[idx] + add[idx];
        if (idx >= 1) {
            add[idx - 1] += add[idx];
        }
        add[idx] = 0;
        --idx;
        return ret;
    }
    
    void increment(int k, int val) {
        k = min(k - 1, idx);
        if (k >= 0) {
            add[k] += val;
        }
    }
};