#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& A) {
    for (int i = 0; i < A.size(); i++) {
        A[i] = A[i] * A[i];
    }
    sort(A.begin(), A.end());
    return A;
}

vector<int> sortedSquares(vector<int>& A) {
    int n = A.size();
    vector<int> res(n);
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (A[i] < 0) {
            index = i;
        } else break;
    }

    int left = index, right = index + 1;
    while (left >= 0 || right < n) {
        if (left < 0) {
            res.push_back(A[right] * A[right]);
            right++;
        } else if (right == n) {
            res.push_back(A[left] * A[left]);
            left--;
        } else if (A[left] * A[left] < A[right] * A[right]) {
            res.push_back(A[left] * A[left]);
            left--;
        } else {
            res.push_back(A[right] * A[right]);
            right++;
        }
    }
    return res;
}

vector<int> sortedSquares(vector<int>& A) {
    int n = A.size();
    int i = 0, j = n - 1;
    vector<int> res(n);
    for (int k = n - 1; k >= 0; k--) {
        if (A[i] * A[i] > A[j] * A[j]) {
            res[k] = A[i] * A[i];
            i++;
        } else {
            res[k] = A[j] * A[j];
            j--;
        }
    }
    return res;
}