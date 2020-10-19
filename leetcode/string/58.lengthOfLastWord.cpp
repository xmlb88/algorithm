#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfLastWord(string s) {
    int n = s.size();
    int i = n - 1;
    while (s[i] == ' ') {
        i--;
    }
    
    int res = 0;
    while (isalpha(s[i]) && i >= 0) {
        res++;
        i--;
    }
    return res;
}