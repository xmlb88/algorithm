#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> board(5, string(5, '.'));

    for (auto it : board) {
        cout << it <<endl;
    }

    cout << board[3][3] <<endl;

    return 0;
}