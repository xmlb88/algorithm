#include <iostream>
using namespace std;

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

int main() {
    f(42, 2.56); // wrong
}