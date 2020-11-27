#include <iostream>
#include <vector>
using namespace std;

// void merge(vector<int>& A, int m, vector<int>& B, int n) {
//     int id = A.size() - 1;
//     while (m > 0 || n > 0) {
//         if (m == 0 || (n > 0 && A[m - 1] < B[n - 1])) {
//             A[id] = B[n - 1];
//             n--;
//         } else if (n == 0 || (m > 0 && A[m - 1] >= B[n - 1])) {
//             A[id] = A[m - 1];
//             m--;
//         }
//         id--;
//     }
// }

void merge(vector<int>& A, int m, vector<int>& B, int n) {
    int index = m + n - 1;
    m--;
    n--;
    while (n >= 0) {
        if (m >= 0 && A[m] > B[n]) {
            A[index] = A[m];
            m--;
        } else {
            A[index] = B[n];
            n--;
        }
        index--;
    }
}

int main() {
    vector<int> A = {1, 2, 3, 0, 0, 0};
    vector<int> B = {2, 5, 6};
    merge(A, 3, B, 3);
}