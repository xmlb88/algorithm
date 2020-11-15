#include <iostream>
#include <vector>
using namespace std;

vector<double> twoSum(int n) {
    double f = 1 / 6.0;
    vector<double> pre(6, f);
    for (int i = 2; i <= n; i++) {
        vector<double> tmp(5 * i + 1, 0);
        for (int j = 0; j < pre.size(); j++) {
            for (int x = 0; x <= 5; x++) {
                tmp[j + x] += pre[j] / 6;
            }
        }
        pre = tmp;
    }
    return pre;
}
