#include <iostream>
#include <vector>
using namespace std;

// 空间优化
int minSwap(vector<int>& A, vector<int>& B) {
    // n:natural s:wapped
    int n1 = 0, s1 = 1;
    for (int i = 1; i < A.size(); i++) {
        int n2 = INT_MAX, s2 = INT_MAX;
        if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
            n2 = min(n2, n1);
            s2 = min(s2, s1 + 1);
        }

        if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
            n2 = min(n2, s1);
            s2 = min(s2, n1 + 1);
        }

        n1 = n2;
        s1 = s2;
    }

    return min(n1, s1);
}

int minSwap(vector<int>& A, vector<int>& B) {
    int len = A.size();
    vector<int> keep(len, INT_MAX);
    vector<int> swap(len, INT_MAX);
    keep[0] = 0, swap[0] = 1;
    for (int i = 1; i < len; i++) {
        if ((A[i] > A[i - 1] && B[i] > B[i - 1]) && (A[i] > B[i - 1] && B[i] > A[i - 1])) {
            keep[i] = min(keep[i - 1], swap[i - 1]);
            swap[i] = min(keep[i - 1], swap[i - 1]) + 1;
            continue;
        }

        if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
            keep[i] = keep[i - 1];
            swap[i] = swap[i - 1] + 1;
        }

        if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
            keep[i] = swap[i - 1];
            swap[i] = keep[i - 1] + 1;
        }
    }

    return min(keep[len - 1], swap[len - 1]);
}

// 空间优化
int minSwap(vector<int>& A, vector<int>& B) {
    int len = A.size();
    int keep = 0, swap = 1;
    for (int i = 1; i < len; i++) {
        bool case1 = A[i] > A[i - 1] && B[i] > B[i - 1];
        bool case2 = A[i] > B[i - 1] && B[i] > A[i - 1];

        if (case1 && case2) {
            int temp = min(keep, swap);
            keep = temp;
            swap = temp + 1;
        } else if (case1) {
            swap++;
        } else if (case2) {
            int temp = keep;
            keep = swap;
            swap = temp + 1;
        }
    }

    return min(keep, swap);
}