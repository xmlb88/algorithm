#include <iostream>
#include <vector>
using namespace std;

int sumOddLengthSubarrays(vector<int>& arr) {
    int sum = 0;
    for (int i = 1; i <= arr.size(); i += 2) {
        for (int j = 0; j + i < arr.size() + 1; j++) {
            sum += sumOfSubarrays(arr, j, j + i);
        }
    }
    return sum;
}

int sumOfSubarrays(vector<int>& arr, int i, int j) {
    int sum = 0;
    for (int k = i; k < j; k++) {
        sum += arr[k];
    }
    return sum;
}