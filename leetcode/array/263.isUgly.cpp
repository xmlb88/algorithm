#include <iostream>
using namespace std;

bool isUgly(int num) {
    if (num == 0) return false;
    while (num % 2 == 0) {
        num /= 2;
    }
    while (num % 3 == 0) {
        num /= 3;
    }
    while (num % 5 == 0) {
        num /= 5;
    }
    return num == 1;
}

bool isUgly(int num) {
    if (num == 0) return false;
    if (num == 1) return true;

    while (true) {
        if (num % 2 == 0) num /= 2;
        else if (num % 3 == 0) num /= 3;
        else if (num % 5 == 0) num /= 5;
        else break;
    }
    return num == 1;
}