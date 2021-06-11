#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ¥Û∂•∂—
vector<int> smallestK(vector<int>& arr, int k) {
    vector<int> res;
    priority_queue<int, vector<int>, less<int>> q;
    for (int i = 0; i < arr.size(); ++i) {
        q.push(arr[i]);
        if (q.size() > k) q.pop();
    }
    while (!q.empty()) {
        res.push_back(q.top());
        q.pop();
    }
    return res;
}

// øÏÀŸ≈≈–Ú
int partition(vector<int>& arr, int left, int right) {
    srand(time(NULL));
    int xindex = rand() % (right - left + 1) + left;
    swap(arr[left], arr[xindex]);

    int key = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= key) --right;
        if (left < right) arr[left] = arr[right];
        while (left < right && arr[left] <= key) ++left;
        if (left < right) arr[right] = arr[left];
    }

    arr[left] = key;
    return left;
}

void helper(vector<int>& arr, int k, int left, int right) {
    int pos = partition(arr, left, right);
    if (pos == k - 1) return;
    else if (pos > k - 1) helper(arr, k, left, pos - 1);
    else helper(arr, k, pos + 1, right);
}

vector<int> smallestK(vector<int>& arr, int k) {
    if (k == 0) return {};
    helper(arr, k, 0, arr.size() - 1);
    vector<int> res;
    for (int i = 0; i < k; ++i) {
        res.push_back(arr[i]);
    }
    return res;
}