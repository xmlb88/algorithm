#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
    vector<int> isprime(n, true);
    int count = 0;
    for (int i = 2; i * i <= n; i++) {
        if (isprime[i]) {
            for (int k = i * i; k <= n; k += i) {
                isprime[k] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isprime[i]) count++;
    }

    return count;
}