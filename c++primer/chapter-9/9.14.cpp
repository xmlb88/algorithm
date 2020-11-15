#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

int main() {
    list<char*> l{"hello", "world"};
    // vector<string> vec(l.begin(), l.end());
    vector<string> vec;
    vec.assign(l.begin(), l.end());
    for (auto s : vec) {
        cout << s << endl;
    }
    return 0;
}