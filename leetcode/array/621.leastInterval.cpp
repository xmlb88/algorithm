#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    int m = tasks.size();
    if (n == 0) return m;
    if (m == 0) return 0;
    int count = 0;
    vector<int> vec(26, 0);
    for (char c : tasks) {
        vec[c - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        count = max(count, vec[i]);
    }
    int max_count = 0;
    for (int i = 0; i < 26; i++) {
        if (vec[i] == count) max_count++;
    }

    return max((count - 1) * (n + 1) + max_count, m);
}