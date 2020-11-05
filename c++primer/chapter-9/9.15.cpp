#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1{1, 2, 3};
    vector<int> v2{1, 2, 4};
    vector<int> v3{1, 2, 3};
    // cout << v1 == v2 << endl << v1 == v3 << endl;
    if (v1 == v2) {
        cout << "v1 == v2" << endl;
    } else cout << "v1 != v2" << endl;

    if (v1 == v3) {
        cout << "v1 == v3" << endl;
    } else cout << "v1 != v3" << endl;
    
    return 0;
}