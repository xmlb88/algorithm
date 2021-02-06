#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int left = k - 1, right = n - 1;
    int sum = 0;
    for (int i = 0; i <= left; i++) {
        sum += cardPoints[i];
    }

    int maxSum = sum;
    while (left >= 0) {
        sum += cardPoints[right] - cardPoints[left];
        maxSum = max(maxSum, sum);
        left--; right--;
    }

    return maxSum;
}

// »¬²»ÒªµÄ
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int windowSize = n - k;
    int sum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
    int minSum = sum;
    for (int i = windowSize; i < n; i++) {
        sum += cardPoints[i] - cardPoints[i - windowSize];
        minSum = min(minSum, sum);
    }
    return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
}