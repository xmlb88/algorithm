#include <iostream>
#include <vector>
using namespace std;

int minArray(vector<int>& numbers) {
    int n = numbers.size();
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (numbers[mid] > numbers[r]) {
            l = mid + 1;
        } else if (numbers[mid] < numbers[r]) {
            r = mid;
        } else if (numbers[mid] == numbers[r]) {
            r--;
        }
    }
    return numbers[l];
}