#include <iostream>
#include <vector>
using namespace std;

double largestSumOfAverages(vector<int>& A, int K) {
    int n = A.size();
    // Ç°×ººÍ
    double<int> preSum(n + 1);
    for (int i = 1; i <= n; i++) {
        preSum[i] = preSum[i - 1] + A[i - 1];
    }
    // TODO:

}

double largestSumOfAverages(vector<int>& A, int K) {
    
}