#include <iostream>
#include <vector>
using namespace std;

// int arrangeCoins(int n) {
//     int i = 1;
//     long num = 0;
//     while (true) {
//         num += i;
//         if (num == n) return i;
//         if (num > n) return i - 1;
//         i++;
//     }
//     return -1;
// }
// 1 2 3

int arrangeCoins(int n) {
    long left = 0, right = n;
    while (left <= right) {
        int mid = left + right >> 1;
        long need = static_cast<double>(1 + mid) / 2 * mid;
        if (need == n) return mid;
        else if (need < n) {
            left = mid + 1;
        } else if (need > n) {
            right = mid - 1;
        }
    }
    return left - 1;
}

int main() {
    cout << arrangeCoins(8) << endl;
}