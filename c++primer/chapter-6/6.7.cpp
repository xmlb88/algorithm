#include <iostream>
using namespace std;

void f() {
    cout << "f()" << endl;
}

void f(int) {
    cout << "f(int)" << endl;
}

void f(int, int) {
    cout << "f(int, int)" << endl;
}

void f(double, double = 3.14) {
    cout << "f(double, double = 3.14)" << endl;
}

int main() {
    // f(5.6);
    // f(42, 2.56);
}

6.54: typedef int func(int&, int&)
        using func = int (int&, int&)
        vector<func*>()