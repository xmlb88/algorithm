#include <iostream>
#include <string>
using namespace std;

bool oneEditAway(string first, string second) {
    if (first == second) return true;
    int n = first.size(), m = second.size();
    if (abs(n - m) >= 2) return false;

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (first[i] == second[j]) {
            i++;
            j++;
        } else {
            return first.substr(i + 1) == second.substr(j) || first.substr(i) == second.substr(j + 1) || first.substr(i + 1) == second.substr(j + 1);
        }
    }

    return true;

    // int i = 0;
    // while (i < n && i < m && first[i] == second[i]) i++;
    // return first.substr(i + 1) == second.substr(i) || first.substr(i) == second.substr(i + 1) || first.substr(i + 1) == second.substr(i + 1);
}