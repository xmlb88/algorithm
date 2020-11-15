#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> res{10, "ji"};
    // cout << res << endl;
    for (auto str : res) {
        cout << str << endl;
    }
}