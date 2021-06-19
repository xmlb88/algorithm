#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// TODO:
int max_length = 0;
// unordered_set<string> st;

bool check(string& str) {
    vector<int> count(26, 0);
    for (char c : str) {
        if (count[c - 'a'] >= 1) return false;
        ++count[c - 'a'];
    }
    return true;
}

void backtrace(vector<string>& arr, string str, int start) {
    int n = arr.size();
    if (check(str)) {
        max_length = max(max_length, static_cast<int>(str.size()));
    }
    else return;
    if (start == n) return;

    backtrace(arr, str, start + 1);
    backtrace(arr, str + arr[start], start + 1);
}

int maxLength(vector<string>& arr) {
    backtrace(arr, "", 0);
    return max_length;
}

int main() {
    vector<string> arr = {"un", "iq", "ue"};
    maxLength
}