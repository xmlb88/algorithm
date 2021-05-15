#include <iostream>
#include <vector>
using namespace std;

// [1, 0, 2, 3, 4]
int maxChunksToSorted(vector<int>& arr) {
    int ans = 0, max = 0;
    for (int i = 0; i < arr.size(); ++i) {
        max = std::max(max, arr[i]);
        if (max == i) ans++;
    }
    return ans;
}