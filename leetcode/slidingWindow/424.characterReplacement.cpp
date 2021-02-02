#include <iostream>
#include <string>
using namespace std;

// WA
// int characterReplacement(string s, int k) {
//     int n = s.size();
//     if (n <= k) return n;
//     int res = 0;

//     int left = 0, right = 0;
//     while (right < n) {
//         int count = 0;
//         int index = -1;
//         char c = s[left];
//         while (right < n) {
//             if (s[right] != c) {
//                 count++;
//                 if (index == -1) {
//                     index = right;
//                 }

//                 if (count > k) break;
//             }
//             right++;
//         }

//         res = max(res, right - left);

//         if (index != -1) {
//             left = index;
//             right = index;
//         }
//     }

//     return res;
// }

// int main() {
//     string s = "ABBB";
//     cout << characterReplacement(s, 2) << endl;
// }

int characterReplacement(string s, int k) {
    vector<int> num(26);
    int n = s.size();
    int maxn = 0;
    int left = 0, right = 0;
    while (right < n) {
        num[s[right] - 'A']++;
        maxn = max(maxn, num[s[right] - 'A']);
        if (right - left + 1 - maxn > k) {
            num[s[left] - 'A']--;
            left++;
        }
        right++;
    }
    return right - left;
}

int characterReplacement(string s, int k) {
    vector<int> num(26, 0);
    int n = s.size();
    int maxn = 0;
    int left = 0, right = 0;
    while (right < n) {
        num[s[right] - 'A']++;
        maxn = max(maxn, num[s[right] - 'A']);
        right++;

        if (right - left - maxn > k) {
            num[s[left] - 'A']--;
            left++;
        }
    }
    return right - left;
}