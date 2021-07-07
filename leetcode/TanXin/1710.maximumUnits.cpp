#include <iostream>
#include <vector>
using namespace std;

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });

    int units = 0;
    for (auto& box : boxTypes) {
        int cnt = min(box[0], truckSize);
        units += cnt * box[1];
        truckSize -= cnt;
        if (truckSize == 0) break;
    }
    return units;
}