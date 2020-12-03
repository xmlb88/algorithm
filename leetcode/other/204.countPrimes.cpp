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

// °£ÊÏÉ¸
int countPrimes(int n) {
    vector<bool> prime(n, true);
    for (int i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            } 
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
        if (prime[i]) count++;
    }
    return count;
}

// ÏßÐÔÉ¸
int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    vector<int> primes;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }

        for (int j = 0; j < primes.size() && i * primes[j] < n; j++) {
            isPrime[i * primes[j]] = false;
            if (i % primes[j] == 0) break;
        }
    }
    return primes.size();
}

int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    vector<int> primes;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }

        for (int j = 0; j < primes.size() && i * primes[j] < n; j++) {
            isPrime[i * primes[j]] = false;
            if (i % primes[j] == 0) break;
        }
    }
    return primes.size();
}

// 2, 3, 4, 5, 6, 7, 8, 9, 10 ...
// primes : 2 (4) 3(6, 9) 5(10, 15, 25)
// 4(8) 6(12)