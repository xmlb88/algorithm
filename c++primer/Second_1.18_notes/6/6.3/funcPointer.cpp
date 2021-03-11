#include <iostream>
#include <string>
using namespace std;


bool lengthCompare(const string &s1, const string &s2) {
    return s1.size() == s2.size();
}

typedef bool FuncP(const string &, const string &);
typedef decltype(lengthCompare) *FuncP2;
using FuncP3 = bool (const string &, const string &);

int main() {
    bool (*pf)(const string &, const string &);
    pf = lengthCompare;
    pf = &lengthCompare;
    cout << boolalpha << pf("this", "that") << endl
        << (*pf)("hello", "gooldbye") << endl
        << lengthCompare("hello", "strue") << endl;
    cout << "====================\n";

    FuncP* funcp = lengthCompare;
    cout << funcp("hello", "hello") << endl;
    FuncP2 funcp2 = lengthCompare;
    cout << funcp2("hello", "uhello") << endl;
    FuncP3* funcp3 = lengthCompare;
    cout << funcp3("hello", "nohello") << endl;
}