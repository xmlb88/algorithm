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

    const int i1 = 35;
    // int const *cptr = &i1;
    const int *cptr = &i1;
    cout << *cptr << endl;
    const int i2 = 1204;
    cptr = &i2;
    cout << *cptr << endl;

    int i3 = 46;
    int* const cptr2 = &i3;
    cout << *cptr2 << endl;
    // cptr2 = cptr;
    *cptr2 = 87;
    cout << *cptr2 << " " << i3 << endl;
}