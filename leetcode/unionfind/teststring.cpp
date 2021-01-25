#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "\\fasdgasdf\\fdafds\\";
    
    int n = str.size();
    cout << n << endl;

    for (int i = 0; i < n; i++) {
        cout << str[i] << " ";
    }

}