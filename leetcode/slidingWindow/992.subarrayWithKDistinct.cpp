#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* TODO: */
int subarrayWithKDistinct(vector<int>& A, int K) {
    int n = A.size();
    int res = 0;
    int left = 0, right = 0;
    unordered_map<int, int> window;
    
}