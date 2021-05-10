#include <iostream>
#include <vector>
using namespace std;

int minCostToMoveChips(vector<int>& position) {
    int odd = 0, even = 0;
    for (int pos : position) {
        if (pos & 1) ++odd;
        else ++even;
    }

    return odd < even ? odd : even;
}