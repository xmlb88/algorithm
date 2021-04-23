#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> a{"1", "@", "a"};
    for (auto _c : a) {
        cout << _c << endl;
    }
}
