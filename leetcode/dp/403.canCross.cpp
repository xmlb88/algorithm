#include <iostream>
#include <vector>
using namespace std;

bool canCross(vector<vector<int>>& stones) {
    int n = stones.size();
    if (n <= 1) return true;
    if (stones[1] != stones[0] + 1) return false;

    // TODO:
}