#include <iostream>
using namespace std;

int main() {
    int i = 42;
    int &r1 = i;
    const int &r2 = i;
    cout << "r2:" << r2 << endl;
    r1 = 0;
    cout << "i:" << i << endl;
    cout << "r2:" << r2 << endl;
}