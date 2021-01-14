#include <iostream>
#include <vector>
using namespace std;

vector<bool> prefixesDivBy5(vector<int>& A) {
    vector<bool> res(A.size(), false);
    int num = 0;
    for (int i = 0; i < A.size(); i++) {
        num = (num * 2 + A[i]) % 5;
        if (num == 0) res[i] = true;
    }
    return res;
}