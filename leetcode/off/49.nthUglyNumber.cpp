#include <iostream>
#include <vector>
using namespace std;

int nthUglyNumber(int n) {
    vector<int> ugly(n);
    int p_2 = 0, p_3 = 0, p_5 = 0;
    ugly[0] = 1;
    for (int i = 1; i < n; i++) {
        ugly[i] = min(min(2 * ugly[p_2], 3 * ugly[p_3]), 5 * ugly[p_5]);
        if (ugly[i] == 2 * ugly[p_2]) p_2++;
        if (ugly[i] == 3 * ugly[p_3]) p_3++;
        if (ugly[i] == 5 * ugly[p_5]) p_5++;
    }
    return ugly[n - 1];
}