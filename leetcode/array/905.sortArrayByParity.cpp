#include <iostream>
#include <vector>
using namespace std;

// Ë«Ö¸Õë
vector<int> sortArrayByParity(vector<int>& A) {
    int i = 0, j = A.size() - 1;
    while (i < j) {
        while (i < j && (A[i] & 1) == 0) i++;
        while (i < j && (A[j] & 1)) j--;
        swap(A[i], A[j]);
    }
    return A;
}
