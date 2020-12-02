#include <iostream>
#include <vector>
using namespace std;

vector<int> divingBoard(int shorter, int longer, int k) {
    if (k == 0) return {};
    if (shorter == longer) return {shorter * k};
    vector<int> res;
    int n = k;
    while (k >= 0) {
        res.push_back(k * shorter + longer * (n - k));
        k--;
    }
    return res;
}