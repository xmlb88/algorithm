#include <iostream>
using namespace std;

int main() {
    char a = 'A' | ' ';
    char c = 'a' | ' ';
    cout << a << endl << c << endl;

    char b = 'b' & '_';
    char d = 'B' & '_';
    cout << b << endl << d << endl;

    char p = 'd' ^ ' ';
    char q = 'D' ^ ' ';
    cout << p << endl << q << endl;
    return 0;
}