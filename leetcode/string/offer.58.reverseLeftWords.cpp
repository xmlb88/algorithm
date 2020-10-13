#include <iostream>
#include <string>
using namespace std;

string reverseLeftWords(string s, int n) {
    return s.substr(n) + s.substr(0, n);
}

int main() {
    string s = "abcdrfghi";
    string q = reverseLeftWords(s, 2);
    cout << q << endl;
}