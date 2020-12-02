#include <iostream>
#include <vector>
using namespace std;

// TODO:
// 暴力 超时
vector<int> constructArr(vector<int>& a) {
    int n = a.size();
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int res = 1;
        for (int j = 0; j < i; j++) {
            res *= a[j];
        }
        for (int j = i + 1; j < n; j++) {
            res *= a[j];
        }
        b[i] = res;
    }
    return b;
}

// 对称遍历
vector<int> constructArr(vector<int>& a) {
    int n = a.size();
    vector<int> b(n, 1);

    for (int i = 1; i < n; i++) {
        b[i] = b[i - 1] * a[i - 1];
    }

    int temp = 1;
    for (int i = n - 2; i >= 0; i--) {
        temp *= a[i + 1];
        b[i] *= temp;
    }

    return b;
}