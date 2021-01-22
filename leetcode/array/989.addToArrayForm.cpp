#include <iostream>
#include <vector>
using namespace std;

vector<int> addToArrayForm(vector<int>& A, int K) {
    int n = A.size();
    vector<int> res;
    for (int i = n - 1; i >= 0; i--) {
        int sum = A[i] + (K % 10);
        res.push_back(sum % 10);
        K /= 10;
        if (sum >= 10) K += 1;
    }

    while (K) {
        res.push_back(K % 10);
        K /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}