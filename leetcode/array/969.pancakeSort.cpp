#include <iostream>
#include <vector>
using namespace std;

vector<int> res;
vector<int> pancakeSort(vector<int>& arr) {
    pancake(arr, arr.size());
    return res;
}


void pancake(vector<int>& arr, int n) {
    if (n == 1) return;

    int maxNum = arr[0];
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
            maxIndex = i;
        }
    }

    sort(arr, 0, maxIndex);
    sort(arr, 0, n - 1);
    res.push_back(maxIndex + 1);
    res.push_back(n);
    pancake(arr, n - 1);
}

void sort(vector<int>& arr, int i, int j) {
    while (i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}