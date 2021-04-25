#include <iostream>
#include <vector>
#include <memory>
using namespace std;

shared_ptr<vector<int>> alloc_vector() {
    return make_shared<vector<int>>();
}

void assign_vector(shared_ptr<vector<int>> p) {
    int i;
    while (cin >> i) {
        p -> push_back(i);
    }
}

void print_vector(shared_ptr<vector<int>> p) {
    for (auto i : *p) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    auto p = alloc_vector();
    assign_vector(p);
    print_vector(p);
    return 0;
}