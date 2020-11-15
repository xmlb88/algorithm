#include <iostream>
using namespace std;

int sumNums(int n) {
    n && (n += sumNums(n - 1));
    return n;
}

