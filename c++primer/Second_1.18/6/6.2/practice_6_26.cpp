#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv) {
    cout << argc << endl;
    for (int i = 1; i < argc; i++) {
        cout << argv[i] << " ";
    }
    cout << endl;
    cout << (argv[5] == 0) << endl;
}