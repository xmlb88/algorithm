#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
    vector<vector<int>> res;
    for (int i = 1; i <= 1000; ++i) {
        int left = 1, right = 1000;
        if (customfunction.f(i, left) > z) break;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (customfunction.f(i, mid) == z) {
                res.push_back({i, mid});
                break;
            } else if (customfunction.f(i, mid) < z) {
                left = mid + 1;
            } else right = mid - 1;
        }
    }
    return res;
}


vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
    vector<vector<int>> res;
    int x = 1;
    while (true) {
        int left = 1, right = 1000;
        if (customfunction.f(x, left) > z) break;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (customfunction.f(x, mid) == z) {
                res.push_back({x, mid});
                break;
            } else if (customfunction.f(x, mid) < z) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        ++x;
    }
    return res;
}


// Ë«Ö¸Õë
vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
    vector<vector<int>> res;
    int left = 1, right = 1000;
    while (left <= 1000 && right >= 1) {
        int t = customfunction.f(left, right);
        if (t == z) {
            res.push_back({left, right});
            ++left; --right;
        } else if (t < z) {
            ++left;
        } else --right;
    }
    return res;
}