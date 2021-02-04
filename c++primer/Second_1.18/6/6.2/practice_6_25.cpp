#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    cout << argc << endl;
    string s(argv[0]);
    s += argv[1];
    s += argv[2];
    cout << s << endl;
}