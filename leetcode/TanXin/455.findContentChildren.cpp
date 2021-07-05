#include <iostream>
#include <vector>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int n = g.size(), m = s.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child = 0, biscuit = 0;
    int res = 0;
    while (child < n && biscuit < m) {
        if (s[biscuit] >= g[child]) {
            res++;
            child++;
        }
        biscuit++;
    }
    return res;
}


// TODO:
int findContentChildren(vector<int>& g, vector<int>& s) {
    int n = g.size(), m = s.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child = 0, biscuit = 0;
    while (child < n && biscuit < m) {
        if ()
    }
}