#include <iostream>
#include <vector>
#include <string>
using namespace std;

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

// º¯Êı
typedef int pf1(int, int);
using pf2 = int (int, int);
// º¯ÊıÖ¸Õë
typedef int (*pf3)(int, int);
using pf4 = int (*)(int, int);

int main() {
    vector<int (*)(int, int)> v;
    v.push_back(add); v.push_back(subtract); v.push_back(multiply); v.push_back(divide);
    for (int (*f)(int, int) : v) {
        cout << (*f)(3, 4) << endl;
    }
}
