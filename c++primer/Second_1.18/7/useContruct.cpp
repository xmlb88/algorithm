#include <iostream>
#include "Sales_data.h"
using namespace std;

int main() {
    Sales_data sd1;
    print(cout, sd1);
    cout << "\n=============\n";

    Sales_data sd2("123-sd2");
    print(cout, sd2);
    cout << "\n=============\n";

    Sales_data sd3("123-sd3", 23, 56.56);
    print(cout, sd3);
    cout << "\n=============\n";

    cout << "please input data:";
    Sales_data sd4(cin);
    print(cout, sd4);
    cout << "\n=============\n";
}