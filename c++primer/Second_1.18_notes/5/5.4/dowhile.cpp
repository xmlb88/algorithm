#include <iostream>
#include <string>
using namespace std;

int main() {
    string rsp;
    do {
        cout << "please enter two values: ";
        int val1 = 0, val2 = 0;
        cin >> val1 >> val2;
        cout << "The sum of " << val1 << " and " << val2
            << " = " << val1 + val2 << "\n\n"
            << "More? Enter yes or no: ";
        cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');
}