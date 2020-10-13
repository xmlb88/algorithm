#include <iostream>
#include <vector>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxCandies = INT_MIN;
    vector<bool> res;
    for (int i = 0; i < candies.size(); i++) {
        maxCandies = max(maxCandies, candies[i]);
    }

    for (int i = 0; i < candies.size(); i++) {
        if (extraCandies + candies[i] >= maxCandies) {
            res.push_back(true);
        } else res.push_back(false);
    }

    return res;
}