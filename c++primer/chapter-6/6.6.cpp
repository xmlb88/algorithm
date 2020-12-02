#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#define NDEBUG

int main() {
    string s;
    cin >> s;
    
    // if (s.size() < 5) {
    //     cerr << "Error: " << __FILE__
    //         << " : in function " << __func__
    //         << " at line " << __LINE__ << endl
    //         << "    compiled on " << __DATE__
    //         << " at " << __TIME__ << endl
    //         << "    word read was \"" << s
    //         << "\" : Length too short " << endl;
    // }

    #ifndef NDEBUG
        cerr << __func__ << ": string size is " << s.size() << endl;
    #endif
    // assert(s.size() > 5);

    cout << s << endl;
}