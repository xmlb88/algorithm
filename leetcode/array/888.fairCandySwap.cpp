#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>
using namespace std;

vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int sumA = accumulate(A.begin(), A.end(), 0);
    int sumB = accumulate(B.begin(), B.end(), 0);

    for (const int& numA : A) {
        for (const int& numB : B) {
            if (sumA - numA + numB == sumB - numB + numA) {
                return {numA, numB};
            }
        }
    }
    return {-1, -1};
}

vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    unordered_set<int> us(B.begin(), B.end());
    int sumA = accumulate(A.begin(), A.end(), 0);
    int sumB = accumulate(B.begin(), B.end(), 0);

    for (const int& numA : A) {
        int search = numA - (sumA - sumB) / 2;
        if (us.find(search) != us.end()) {
            return {numA, search};
        }
    }
    return {-1, -1};
}