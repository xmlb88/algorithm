#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findString(vector<string>& words, string s) {
    int left = 0, right = words.size() - 1;
    int mid, temp;

    while (left <= right) {
        mid = left + (right - left) / 2;
        temp = mid;

        while (mid <= right && words[mid].empty()) {
            mid++;
        }

        if (mid == right + 1) {
            right = temp - 1;
            continue;
        }

        if (words[mid] == s) return mid;
        else if (words[mid] > s) right = mid - 1;
        else if (words[mid] < s) left = mid + 1;
    }
    return -1;
}

// ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""]
// "ball"
// left = 0, right = 13 - 1 = 12 mid = 6
// s = "ball" words[mid] = "" s > 