#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Ì°ÐÄ
int update(const string& source, int i, const string& target) {
    int j = 0;
    while (i < target.size() && j < source.size()) {
        if (source[j] == target[i]) {
            i++;
            j++;
        } else {
            j++;
        }
    }
    return i;
}

int shortestWay(string source, string target) {
    int i = 0;
    int res = 0;
    while (i < target.size()) {
        res++;
        int t = update(source, i, target);
        if (t == i) return -1;
        i = t;
    }
    return res;
}