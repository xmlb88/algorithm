#include<iostream>
#include<vector>
using namespace std;

// int countPrimes(int n) {
//     int count = 0;
//     for (int i = 2; i < n; i++) {
//         if (isprime(i)) count++;
//     }
//     return count;
// }

// int isprime(int n) {
//     for (int i = 2; i < n; i++) {
//         if (n % i == 0) return false;
//     }
//     return true;
// }


// 优化1
// int isprime(int n) {
//     for (int i = 2; i * i <= n; i++) {
//         if (n % i == 0) return false;
//     }
//     return true;
// }

// 排除法第一版

// int countPrimes(int n) {
//     // 将数组初始化为true
//     vector<bool> isPrime(n, true);

//     for (int i = 2; i < n; i++) {
//         if (isPrime[i]) {
//             // i的倍数标记为false
//             for (int j = 2 * i; j < n; j += i)
//                 isPrime[j] = false;
//         }
//     }

//     int count = 0;
//     for (int i = 2; i < n; i++) {
//         if (isPrime[i]) count++;
//     }

//     return count;
// }

// 排除法优化
// n = 25, i = 4: 标记 4 * 2 = 8; 4 * 3 = 12; 4 * 4 = 16; 4 * 5 = 20; 4 * 6 = 24;

int countPrimes(int n) {
    vector<int> isPrime(n, true);

    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) count++;
    }

    return count;
}

