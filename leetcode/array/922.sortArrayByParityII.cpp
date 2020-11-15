#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParityII(vector<int>& A) {
    vector<int> res(A.size());
    int even = 0, odd = 1;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] & 1) {
            res[odd] = A[i];
            odd += 2;
        } else {
            res[even] = A[i];
            even += 2;
        }
    }
    return res;
}

vector<int> sortArrayByParityII(vector<int>& A) {
    int n = A.size();
    int j = 1;
    for (int i = 0; i < A.size(); i += 2) {
        if (A[i] & 1) {
            while (A[j] & 1) {
                j += 2;
            }
            swap(A[i], A[j]);
        }
    }
    return A;
}