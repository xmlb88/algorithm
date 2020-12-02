#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int nthUglyNumber(int n) {
    vector<int> ugly(n);
    ugly.at(0) = 1;
    int p_2 = 0, p_3 = 0, p_5 = 0;
    for (int i = 1; i < n; i++) {
        ugly.at(i) = min(min(2 * ugly.at(p_2), 3 * ugly.at(p_3)), 5 * ugly.at(p_5));
        if (ugly.at(i) == 2 * ugly.at(p_2)) p_2++;
        if (ugly.at(i) == 3 * ugly.at(p_3)) p_3++;
        if (ugly.at(i) == 5 * ugly.at(p_5)) p_5++;
    }
    return ugly[n - 1];
}