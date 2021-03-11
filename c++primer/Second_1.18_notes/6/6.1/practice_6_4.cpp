#include <iostream>
#include <string>
using namespace std;

int fact(int i) {
    return i > 1 ? i * fact(i - 1) : 1;
}

void interactive_fact() {
    const string promt = "Enter a number within [1, 13) : ";
    const string out_of_range = "Out of range, please try again. \n";
    for (int i; cout << promt, cin >> i;) {
        if (i < 1 || i > 12) {
            cout << out_of_range;
            continue;
        }
        cout << fact(i) << endl;
    }
}

int main() {
    interactive_fact();
    return 0;
}