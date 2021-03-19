#include <iostream>
#include <vector>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    // right_bound
    int left = 0, right = letters.size();
    while (left < right) {
        int mid = left + right >> 1;
        if (letters[mid] == target) {
            left = mid + 1;
        } else if (letters[mid] > target) {
            right = mid;
        } else if (letters[mid] < target) {
            left = mid + 1;
        }
    }

    return right == letters.size() ? letters[0] : letters[right];
}