#include <iostream>
using namespace std;

void swapWithPointer(int *p, int *q) {
    swap(*p, *q);
}

int main() {
    int i, j;
    cin >> i >> j;
    swapWithPointer(&i, &j);
    cout << i << " " << j << endl;
}