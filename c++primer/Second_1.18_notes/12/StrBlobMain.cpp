#include <iostream>
#include "StrBlob.h"
using namespace std;

int main() {
    const StrBlob csb{"hello", "word", "pezy"};
    StrBlob sb{"hello", "world", "Mooophy"};
    cout << csb.front() << " " << csb.back() << endl;
    sb.back() = "pezy";
    cout << sb.front() << " " << sb.back() << endl;
}