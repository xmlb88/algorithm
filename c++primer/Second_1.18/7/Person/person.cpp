#include <iostream>
#include "Person.h"
using namespace std;

int main() {
    cout << "enter name and address :";
    Person p(cin);
    print(cout, p);
}