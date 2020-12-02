#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    vector <int> vec;
    MedianFinder() {

    }
    
    void addNum(int num) {
        vec.push_back(num);
    }
    
    double findMedian() {
        sort(vec.begin(), vec.end());
        int size = vec.size();
        if (size == 0) return 0.0;
        if (size % 2 == 1) {
            return vec[size / 2] * 1.0;
        } else {
            return (vec[size / 2] + vec[size / 2 - 1]) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class MedianFinder {
private:
    vector<int> store;

public:
    void addNum(int num) {
        if (store.empty())
            store.push_back(num);
        else
            store.insert(lower_bound(store.begin(), store.end(), num), num);
    }

    double findMedian() {
        int n = store.size();
        return n & 1? store[n / 2] : (store[n / 2 - 1] + store[n / 2]) * 0.5;
    }
};


class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> lo; // ´ó¶¥¶Ñ
    priority_queue<int, vector<int>, greater<int>> hi; // Ð¡¶¥¶Ñ
    
    MedianFinder() {

    }
    
    void addNum(int num) {
        lo.push(num);

        hi.push(lo.top());
        lo.pop();

        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        return lo.size() > hi.size() ? (double) lo.top() : (lo.top() + hi.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

