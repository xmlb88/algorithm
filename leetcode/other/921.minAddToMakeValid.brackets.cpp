#include <iostream>
#include <string>
using namespace std;

int minAddToMakeValid(string s) {
    int need_left = 0, need_right = 0;
    for (char c : s) {
        if (c == '(') {
            need_right++;
        } else if (c == ')') {
            need_right--;
            if (need_right == -1) {
                need_right = 0;
                need_left++;
            }
        }
    }

    return need_left + need_right;
}