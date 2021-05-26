#include <iostream>
#include <vector>
using namespace std;

int hammingDistance(int x, int y) {
    int a = x ^ y;
    int count = 0;
    while (a) {
        a &= (a - 1);
        count++;
    }
    return count;
}


int hammingDistance(int x, int y) {
    int a = x ^ y;
    int count = 0;
    while (a) {
        a = a & (a - 1);
        ++count;
    }
    return count;
}