#include <iostream>
#include <string>
using namespace std;

string trim(string s) {
    s.erase(0, s.find_first_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
    return s;
}

int main() {
    string s;
    getline(cin, s);
    s = trim(s);
    cout << s << endl;
    return 0;
}