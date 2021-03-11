#include <iostream>
using namespace std;

int sum(initializer_list<int> li) {
    int sum = 0;
    for (auto it = li.begin(); it != li.end(); it++) {
        sum += *it;
    }
    return sum;
}

int main() {
    cout << sum({1, 2, 4, 5, 6, 6}) << endl;
    cout << sum({1, 2, 3}) << endl;
}