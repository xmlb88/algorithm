#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

string sortString(string s) {
    vector<int> vec(26, 0);
    for (char c : s) {
        vec[c - 'a']++;
    }

    string res;
    while (res.size() < s.size()) {
        for (int i = 0; i < 26; i++) {
            if (vec[i] > 0) {
                res += i + 'a';
                vec[i]--;
            }
        }

        for (int i = 25; i >= 0; i--) {
            if (vec[i] > 0) {
                res += i + 'a';
                vec[i]--;
            }
        }
    }

    return res;
}