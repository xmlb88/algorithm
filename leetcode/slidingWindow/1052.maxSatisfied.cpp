#include <iostream>
#include <vector>
using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int n = customers.size();
    int max_satisfied = 0;
    int satisfied = 0;
    for (int i = 0; i < n; i++) {
        if (grumpy[i] == 0) {
            satisfied += customers[i];
        }
    }

    int left = 0, right = 0;
    while (right < n) {
        if (grumpy[right] == 1) satisfied += customers[right];
        right++;

        if (right - left == X) {
            max_satisfied = max(max_satisfied, satisfied);
            if (grumpy[left] == 1) satisfied -= customers[left];
            left++;
        }
    }
    return max_satisfied;
}