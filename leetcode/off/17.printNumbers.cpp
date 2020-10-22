#include <iostream>
#include <vector>
using namespace std;

vector<int> printNumbers(int n) {
    int maxNumber = 0;
    while (n > 0) {
        maxNumber = maxNumber * 10 + 9;
        n--;
    }

    vector<int> res;
    for (int i = 1; i <= maxNumber; i++) {
        res.push_back(i);
    }
    return res;
}