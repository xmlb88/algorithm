#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int first = 1, second = 2;
    for (int i = 3; i <= n; i++) {
        int tmp = second;
        second = first + second;
        first = tmp;
    }
    return second;
}

int climbStairs(int n) {
    
}