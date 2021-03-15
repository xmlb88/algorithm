#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;
    auto iter = vec.begin();
    for (int i = 0; i < 5; ++i) {
        iter = vec.insert(iter, i);
    }

    cout << "vec :";
    for (int i : vec) {
        cout << i << " ";
    }
}