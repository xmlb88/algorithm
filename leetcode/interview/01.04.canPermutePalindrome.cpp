#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool canPermutePalindrome(string s) {
    unordered_set<char> m;
    for (char c : s) {
        if (m.count(c)) m.erase(c);
        else m.insert(c);
    }

    return m.size() == 0 || m.size() == 1;
}