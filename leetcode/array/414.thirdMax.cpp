#include <iostream>
#include <vector>
#include <set>
using namespace std;

int thirdMax(vector<int>& nums) {
    long first = INT64_MIN, second = INT64_MIN, third = INT64_MIN;
    for (int num : nums) {
        if (num == first || num == second || num == third) continue;

        if (num > first) {
            third = second;
            second = first;
            first = num;
        } else if (num > second) {
            third = second;
            second = num;
        } else if (num > third) {
            third = num;
        } else continue;
    }

    return third == INT64_MIN ? first : third;
}