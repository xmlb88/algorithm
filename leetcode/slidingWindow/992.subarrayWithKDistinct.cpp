#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* TODO: */
// WA
int subarraysWithKDistinct(vector<int>& A, int K) {
    return subarraysMaxKDistinct(A, K) - subarraysMaxKDistinct(A, K - 1);
}

// ��ຬk����ĸ�����������
int subarraysMaxKDistinct(vector<int>& A, int K) {
    int count = 0;
    int n = A.size();
    int left = 0, right = 0;
    unordered_map<int, int> window;
    while (right < n) {
        ++window[A[right]];
        ++right;
        if (window.size() <= K) {
            ++count;
        } else {
            while (window.size() > K) {
                --window[A[left]];
                ++left;
                ++count;
            }
        }
    }
    while (left <= right) {
        ++count;
        ++left;
    }
    return count;
}