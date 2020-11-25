#include <iostream>
#include <vector>
using namesapce std;

static int mod_num = 1000000007;
int waysToStep(int n) {
    if (n < 2) return 1;
    if (n == 2) return 2;
    vector<int> step(n + 1);
    step[0] = 1;
    step[1] = 1;
    step[2] = 2;
    for (int i = 3; i <= n; i++) {
        step[i] = (step[i - 1] + step[i - 2] + step[i - 3]) % mod_num;
    }
    return step[n];
}