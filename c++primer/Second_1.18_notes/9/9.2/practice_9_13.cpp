#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    list<int> li = {1, 2, 3, 4, 5};
    vector<double> vd(li.begin(), li.end());
    for (auto d : vd) {
        cout << d << " ";
    }

    cout << "\n====================" << endl;

    vector<int> vi = {3, 4, 5, 6, 7};
    vector<double> vd2(vi.begin(), vi.end());
    for (auto d : vd2) {
        cout << d << " ";
    }

    cout << "\n====================" << endl;

    // 9_15:
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2 = {1, 2, 3, 4, 5};
    vector<int> vec3 = {1, 2, 3, 4};
    cout << (vec1 == vec2 ? "true" : "false") << endl;
    cout << (vec1 == vec3 ? "true" : "false") << endl;

    // 9_16:
    // list<int> li{1, 2, 3, 4, 5};
    cout << (vector<int> (li.begin(), li.end()) == vec2 ? "true" : "false") << endl;
    cout << (vector<int> (li.begin(), li.end()) == vec3 ? "true" : "false") << endl;



}