// #define NDEBUG
#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    assert(b != 0);
    cout << a / b << endl;
}