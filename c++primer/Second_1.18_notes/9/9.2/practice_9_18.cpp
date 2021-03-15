#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <list>
using namespace std;

int main() {
    // deque<string> dq;
    // string word;
    // while (cin >> word) {
    //     dq.push_back(word);
    // }

    // for (auto it = dq.begin(); it != dq.end(); ++it) {
    //     cout << *it << endl;
    // }


    cout << "\n 9_20====================\n";
    // 9.20:
    list<int> li{1, 2, 3, 4, 5, 6, 7, 8};
    deque<int> odd, even;
    for (int i : li) {
        // if (i & 1) {
        //     odd.push_back(i);
        // } else even.push_back(i);
        (i & 1 ? odd : even).push_back(i);
    }

    cout << "odd: ";
    for (int i : odd) {
        cout << i << " ";
    }
    cout << "\neven: ";
    for (int i : even) {
        cout << i << " ";
    }
    
}