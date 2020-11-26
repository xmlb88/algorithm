#include <iostream>
using namespace std;

int waysToChange(int n) {
    if (n <= 0) return 0;
    if (n < 5) return 1;
    if (n >= 5 && n < 10) return 2;
    if (n >= 10 && n < 15) return 4;
    return waysToChange(n - 25) + waysToChange(n - 10) + waysToChange(n - 5)
}