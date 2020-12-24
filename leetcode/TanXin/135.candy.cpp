#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    if (n == 0) return 0;

    vector<int> left(n, 1), right(n, 1);
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) left[i] = left[i - 1] + 1;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) right[i] = right[i + 1] + 1;
    }

    int num = 0;
    for (int i = 0; i < n; i++) {
        num += max(left[i], right[i]);
    }
    return num;
}


// 1 0 2    
// 1 2 2    1 + 2 + 1