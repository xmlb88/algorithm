#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string key = "acbaacba";
    string ring = "ababcab";
    int n = ring.size();
    vector<int> pos[26];
    for (int i = 0; i < n; i++) {
        pos[ring[i] - 'a'].push_back(i);
    }

    for (auto num : pos) {
        for (auto nu : num) {
            cout << nu << " ";
        }
        cout << endl;
    }
}