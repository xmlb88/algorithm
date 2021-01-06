#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int flipgame(vector<int>& fronts, vector<int>& backs) {
    int n = fronts.size();
    if (n == 0) return 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        if (fronts[i] == backs[i]) {
            s.insert(fronts[i]);
        }
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int num : fronts) {
        q.push(num);
    }
    for (int num : backs) {
        q.push(num);
    }

    while (!q.empty() && s.find(q.top()) != s.end()) {
        s.pop();
    }

    return q.empty() ? 0 : q.top();
}