#include <iostream>

int a;

void printb() {
    int b;
    int c = b;
    std::cout << c << std::endl;
}

int main() {
    std::cout << a << std::endl;
    // std::cout << b << std::endl;
    printb();
    return 0;
}