#include <iostream>
#include <deque>
#include <queue>
#include <string>
using namespace std;

int main() {
    deque<string> dq;
    string word;
    while (cin >> word) {
        dq.push_back(word);
    }

    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << endl;
    }


    // 9.20:
    lsit
}