#include <iostream>
#include <vector>
using namespace std;

typedef int func(int, int);
using PF = int (*) (int, int);

int add(int a, int b) {return a + b;}
int subtract(int a, int b) {return a - b;}
int multiply(int a, int b) {return a * b;}
int divide(int a, int b) {return b != 0 ? a / b : 0;}

int main() {
    vector<PF> v{add, subtract, multiply, divide};
    vector<func*> v{add, subtract, multiply, divide};
    vector<decltype(add)*> v{add, subtract, multiply, divide};
    for (auto f : v) {
        cout << f(2, 3) << endl;
    }
}
