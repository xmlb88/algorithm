#include <iostream>
#include <vector>
using namespace std;

bool isUgly(int n) {
    if (n == 1) return true;
    if (n < 1) return false;
    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;
    return n == 1;
}

// review 2021��4��10��16:36:27
bool isUgly(int n) {
    if (n == 1) return true;
    if (n < 1) return false;
    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;
    return n == 1;
}