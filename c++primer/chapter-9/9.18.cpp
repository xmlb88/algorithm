// #include <bits/stdc++.h>
#include <iostream>
#include <deque>
using namespace std;

int main() {
    string s;
    deque<string> deq;
    while (cin >> s) {
        deq.emplace_back(s);
    }

    for (auto it = deq.begin(); it != deq.end(); it++) {
        cout << *it << endl;
    }
    
}