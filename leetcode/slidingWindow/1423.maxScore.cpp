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

// 滑不要的
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

// 滑不要的
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

// 滑要的
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int score = 0;
    for (int i = 0; i < k; i++) {
        score += cardPoints[i];
    }
    int maxScore = score;
    int left = k - 1, right = n - 1;

    while (left >= 0) {
        score -= cardPoints[left];
        --left;
        score += cardPoints[right];
        --right;
        maxScore = max(maxScore, score);
    }
    return maxScore;
}

// 滑不要的
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int len = n - k;
    int sumScore = accumulate(cardPoints.begin(), cardPoints.end(), 0);
    int score = 0, minScore = INT_MAX;
    int left = 0, right = 0;
    while (right < n) {
        score += cardPoints[right];
        right++;

        if (right - left == len) {
            minScore = min(minScore, score);
            score -= cardPoints[left];
            left++;
        }
    }
    if (minScore == INT_MAX) minScore = 0;
    return sumScore - minScore;
}