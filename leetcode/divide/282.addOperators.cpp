#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> addOperators(string num, int target) {
    vector<string> result;
    string track;
    backtrack(num, target, 0, 0, 1, result, track);
    return result;
}

void backtrack(string num, int target, int index, long val, long mult, vector<string>& result, string& track) {
    if (index == num.size()) {
        if (val == target) result.push_back(track);
        return;
    }

    int len = track.size();
    for (int i = index; i < nums.size(); i++) {
        string sval = num.substr(index, i - index + 1);
        long n = stol(sval);
        if (index == 0) {
            track += sval;
            backtrack(num, target, i + 1, n, n, result, track);
            track.resize(len);
        } else {
            // +
            track += "+" + sval;
            backtrack(num, target, i + 1, val + n, n, result, track);
            track.resize(len);

            // -
            track += "-" + sval;
            backtrack(num, target, i + 1, val - n, -n, result, track);
            track.resize(len);

            // *
            track += "*" + sval;
            backtrack(num, target, i + 1, val - mult + mult * n, mult * n, result, track);
            track.resize(len);
        }
        if (n == 0) return;
    }
}