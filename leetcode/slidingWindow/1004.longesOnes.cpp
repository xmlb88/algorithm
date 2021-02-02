#include <iostream>
#include <vector>
using namespace std;

int longestOnes(vector<int>& A, int k) {
    int n = A.size();
    int left = 0, right = 0;
    int zeroNum = 0;
    while (right < n) {
        if (A[right] == 0) zeroNum++;
        right++;

        if (zeroNum > k) {
            if (A[left] == 0) zeroNum--;
            left++;
        }
    }
    return right - left;
}