#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ±©Á¦
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int count = 0;
    for (int numA : A) {
        for (int numB : B) {
            for (int numC : C) {
                for (int numD : D) {
                    if (numA + numB + numC + numD == 0) count++;
                }
            }
        }
    }
    return count;
}

// ³¬Ê±
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int n = A.size();
    if (n == 0) return 0;
    // sort(C.begin(), C.end());
    // sort(D.begin(), D.end());
    unordered_map<int, int> m;
    for (int numD : D) {
        m[numD]++;
    }
    int count = 0;
    for (int numA : A) {
        for (int numB : B) {
            for (int numC : C) {
                count += m[-(numA + numB + numC)];
            }
        }
    }
    return count;
}

// AC
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    if (A.size() == 0) return 0;
    unordered_map<int, int> m;
    int count = 0;

    for (int numA : A) {
        for (int numB : B) {
            m[numA + numB]++;
        }
    }

    for (int numC : C) {
        for (int numD : D) {
            count += m[-(numC + numD)];
        }
    }

    return count;
}


// int twoSum(vector<int>& C, vector<int>& D, int target) {
//     int count = 0;
//     int n = C.size();
//     int i = 0, j = n - 1;
//     while (i < n && j >= 0) {
//         if (C[i] + D[j] == target) {
//             count++;
//             if (i < n - 1 && C[i + 1] == C[i]) i++;
//             else if (j > 1 && D[j - 1] == D[j]) j--;
//             else {
//                 i++;
//                 j--;
//             }
//         } else if (C[i] + D[j] > target) {
//             j--;
//         } else if (C[i] + D[j] < target) {
//             i++;
//         }
//     }
//     return count;
// }