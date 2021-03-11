#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream fstrm("something.txt");
    string s;
    while (fstrm >> s) {
        cout << s << endl;
    }
    cout << fstrm.is_open() << endl;
    fstrm.close();
    cout << fstrm.is_open() << endl;
    fstrm.open("something.txt");
    ofstream out("sth3.txt", ofstream::app);
    while (getline(fstrm, s)) {
        out << s << endl;
    }
}