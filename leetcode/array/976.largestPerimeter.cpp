#include <iostream>
#include <vector>
using namespace std;

// 超时
// bool isvalid(int a, int b, int c) {
//     return a + b > c;
// }

// int largestPerimeter(vector<int>& A) {
//     if (A.size() < 3) return 0;
//     int res = 0;
//     for(int i = 0; i < A.size() - 2; i++) {
//         for (int j = i + 1; j < A.size() - 1; j++) {
//             for (int k = j + 1; k < A.size(); k++) {
//                 if (isvalid(A[i], A[j], A[k])) {
//                     res = max(res, A[i] + A[j] + A[k]);
//                 }
//             }
//         }
//     }
//     return res;
// }

// bool isvalid(int a, int b, int c) {
//     if (a >= b && a >= c) return b + c > a;
//     if (b >= a && b >= c) return a + c > b;
//     if (c >= a && c >= b) return a + b > c;
//     return false;
// }

int largestPerimeter(vector<int>& A) {
    if (A.size() < 3) return 0;
    sort(A.end(), A.begin());
    for (int i = 0; i < A.size() - 2; i++) {
        if (A[i] < A[i + 1] + A[i + 2]) {
            return A[i] + A[i + 1] + A[i + 2];
        }
    }
    return 0;
}