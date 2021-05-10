#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> addToArrayForm(vector<int>& num, int k) {
    deque<int> dq;
    int add = 0;
    for (int i = num.size() - 1; i >= 0; --i) {
        int sum = num[i] + (k % 10) + add;
        k /= 10;
        add = sum / 10;
        dq.push_front(sum % 10);
    }

    while (add || k) {
        int sum = k % 10 + add;
        k /= 10;
        add = sum / 10;
        dq.push_front(sum % 10);
    }
    return vector<int>(dq.begin(), dq.end());
}


// 
vector<int> addToArrayForm(vector<int>& num, int k) {
    vector<int> res;
    for (int i = num.size() - 1; i >= 0; --i) {
        int sum = num[i] + (k % 10);
        k /= 10;
        if (sum / 10) ++k;
        res.push_back(sum % 10);
    }

    while (k) {
        res.push_back(k % 10);
        k /= 10;
    }

    reverse(res.begin(), res.end());
    return res;
}