#include <iostream>
#include <vector>
using namespace std;

vector<int> exchange(vector<int>& nums) {
    int i = 0, j = nums.size() - 1;
    while (i < j) {
        while (isOdd(nums[i]) && i < j) i++;
        while (!isOdd(nums[j]) && i < j) j--;
        swap(nums[i], nums[j]);
        i++, j--;
    }
    return nums;
}

bool isOdd(int num) {
    return (num % 2) == 1;
}