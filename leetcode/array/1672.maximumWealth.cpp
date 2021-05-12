#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
    int maxWealth = 0;
    for (auto& acc : accounts) {
        int sum = accumulate(acc.begin(), acc.end(), 0);
        maxWealth = max(maxWealth, sum);
    }
    return maxWealth;
}