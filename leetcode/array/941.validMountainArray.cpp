#include <iostream>
#include <vector>
using namespace std;

bool validMountainArray(vector<int>& A) {
    if (A.empty()) return false;
    int i = 0, j = A.size() - 1;
    while (i < A.size() - 1) {
        if (A[i + 1] > A[i]) i++;
        else break;
    }

    while (j >= 1) {
        if (A[j] < A[j - 1]) j--;
        else break;
    }

    return i != 0 && j != A.size() - 1 && i == j;
}