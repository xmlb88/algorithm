#include <iostream>
#include "Chapter6.h"
using namespace std;

int fact(int n) {
    return n > 1 ? n * fact(n - 1) : 1;
}