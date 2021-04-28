#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string smallestGoodBase(string n) {
    long long m = stoll(n);
    for (long long i = 2; i <= m - 1; ++i) {
        if (goodBase(i, m)) return to_string(i);
    }
    return to_string(m - 1);
}

bool goodBase(int a, long long n) {
    int i = 0;
    long long sum;
    while (true) {
        sum += pow(a, i);
        if (sum == n) return true;
        else if (sum > n) return false;
        i++;
    }
}