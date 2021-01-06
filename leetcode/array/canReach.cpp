#include <iostream>
#include <vector>
using namespace std;

bool canReach(vector<int>& arr, int start) {
    vector<bool> visited(arr.size(), false);
    return dfs(arr, start, visited);
}

bool dfs(vector<int>& arr, int start, vector<bool>& visited) {
    if (start < 0 || start >= arr.size()) return false;
    if (arr[start] == 0) return true;

    if (visited[start]) return false;
    visited[start] = true;

    return dfs(arr, start - arr[start], visited) || dfs(arr, start + arr[start], visited);
}