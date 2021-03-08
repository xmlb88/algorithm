#include <iostream>
#include <vector>
#include <string>
using namespace std;

void isPalindRome(string s) {
    int n = s.size();
    vector<vector<bool>> isPalind(n, vector<bool> (n, false));

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (j - i + 1 <= 2 && s[i] == s[j]) isPalind[i][j] = true;
            else if (s[i] == s[j]) isPalind[i][j] = isPalind[i + 1][j - 1];
        }
    }
}

int main() {
    string s = "efe";
    isPalindRome(s);
}