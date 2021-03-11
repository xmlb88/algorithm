#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// istringstream
// ostringstream
// stringstream

int main() {
    string s{"this is a test"};
    // stringstream strm;
    stringstream strm(s);
    cout << strm.str() << endl;
    s = "change this test";
    strm.str(s);
    cout << strm.str() << endl;
}