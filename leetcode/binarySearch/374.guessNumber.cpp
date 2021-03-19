#include <iostream>
#include <vector>
using namespace std;

int guess(int n) {
    if (n == 6) return 0;
    if (n > 6) return -1;
    return 1;
}

// int guessNumber(int n) {
//     int left = 1, right = n;
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (guess(mid) == 0) {
//             return mid;
//         } else if (guess(mid) == 1) {
//             left = mid + 1;
//         } else if (guess(mid) == -1) {
//             right = mid - 1;
//         }
//     }
//     return -1;
// }

int guessNumber(int n) {
    long left = 1, right = n + 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (guess(mid) == 0) {
            return mid;
        } else if (guess(mid) == 1) {
            left = mid + 1;
        } else if (guess(mid) == -1) {
            right = mid;
        }
    }
    return -1;
}

int main() {
    cout << guessNumber(10) << endl;
}

int guessNumber(int n) {
    int left = 1, right = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (guess(mid) == 0) return mid;
        else if (guess(mid) == 1) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}