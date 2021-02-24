#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for (int i = 0; i < A.size(); i++) {
        int lo = 0, hi = A[i].size() - 1;
        while (lo < hi) {
            swap(A[i][lo], A[i][hi]);
            // if (A[i][lo] == 0) A[i][lo] = 1;
            // else if (A[i][lo] == 1) A[i][lo] = 0;

            // if (A[i][hi] == 0) A[i][hi] = 1;
            // else if (A[i][hi] == 1) A[i][hi] = 0;

            A[i][lo] ^= 1;
            A[i][hi] ^= 1;
            lo++, hi--;
        }

        if (lo == hi) {
            // if (A[i][lo] == 0) A[i][lo] = 1;
            // else if (A[i][lo] == 1) A[i][lo] = 0;
            A[i][lo] ^= 1;
        }
    }

    // for (int i = 0; i < A.size(); i++) {
    //     for (int j = 0; j < A[i].size(); j++) {
    //         if (A[i][j] == 0) A[i][j] = 1;
    //         else if (A[i][j] == 1) A[i][j] = 0;
    //     }
    // }
    return A;
}


vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for (int i = 0; i < A.size(); i++) {
        int left = 0, right = A[0].size() - 1;
        while (left < right) {
            swap(A[i][left], A[i][right]);
            A[i][left] ^= 1;
            A[i][right] ^= 1;
            ++left;
            --right;
        }

        if (left == right) {
            A[i][left] ^= 1;
        }
    }
    return A;
}