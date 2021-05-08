#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool canThreePartsEqualSum(vector<int>& arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 3 != 0) return false;
    int part = sum / 3;
    int part_sum = 0;
    int cut = 0;
    for (int i = 0; i < arr.size(); ++i) {
        part_sum += arr[i];
        if (part_sum == part) {
            part_sum = 0;
            cut++;
            if (cut == 2 && i != arr.size() - 1) return true;
        }
    }
    return false;
}