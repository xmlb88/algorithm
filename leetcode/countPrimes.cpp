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


// �Ż�1
// int isprime(int n) {
//     for (int i = 2; i * i <= n; i++) {
//         if (n % i == 0) return false;
//     }
//     return true;
// }

// �ų�����һ��

// int countPrimes(int n) {
//     // �������ʼ��Ϊtrue
//     vector<bool> isPrime(n, true);

//     for (int i = 2; i < n; i++) {
//         if (isPrime[i]) {
//             // i�ı������Ϊfalse
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

// �ų����Ż�
// n = 25, i = 4: ��� 4 * 2 = 8; 4 * 3 = 12; 4 * 4 = 16; 4 * 5 = 20; 4 * 6 = 24;

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

