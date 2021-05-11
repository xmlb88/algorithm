#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main() {
    plus<int> intAdd;
    negate<int> intNegate;
    int sum = intAdd(10, 20);
    cout << sum << endl;
    sum = intNegate(intAdd(10, 20));
    cout << sum << endl;
}