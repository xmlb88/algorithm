#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findLucky(vector<int>& arr) {
    unordered_map<int, int> m;
    for (int num : arr) {
        m[num]++;
    }

    int res = -1;
    for (auto num : m) {
        if (num.first == num.second) {
            res = max(res, num.first);
        }
    }
    return res;
}