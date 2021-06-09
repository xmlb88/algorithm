#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// hash + 堆

struct compare {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    // 最小堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    // 也可以用lambda表达式
    // auto compare = [] (const pair<int, int>& a, const pair<int, int>& b) {
    //     return a.second > b.second;
    // };
    // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
    
    for (int num : nums) {
        m[num]++;
    }

    for (auto p : m) {
        pq.push(p);
        if (pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> res;
    while (!pq.empty()) {
        res.push_back(pq.top().first);
        pq.pop();
    }

    return res;
}

// hash + 快速排序方法
int partition(vector<pair<int, int>>& count, int i, int j) {
    srand(time(NULL));
    int idx = rand() % (j - i  + 1) + i;
    swap(count[i], count[idx]);

    auto key = count[i];
    while (i < j) {
        while (i < j && count[j].second <= key.second) --j;
        if (i < j) count[i] = count[j];
        while (i < j && count[i].second >= key.second) ++i;
        if (i < j) count[j] = count[i];
    }
    count[i] = key;
    return i;
}

void helper(vector<pair<int, int>>& count, int i, int j, int k) {
    if (i >= j) return;
    int pos = partition(count, i, j);
    if (pos == k) return;
    else if (pos > k) helper(count, i, pos - 1, k);
    else if (pos < k) helper(count, pos + 1, j, k);
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int num : nums) {
        m[num]++;
    }

    vector<pair<int, int>> count;
    for (auto p : m) count.push_back(p);

    if (count.size() == 1) return {count[0].first};

    helper(count, 0, count.size() - 1, k - 1);

    vector<int> res;
    for (int i = 0; i < k; ++i) {
        res.push_back(count[i].first);
    }
    return res;
}