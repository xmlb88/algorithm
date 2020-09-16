#include<iostream>
#include<vector>
using namespace std;

void swapNum(int x, int y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int main() {
    int x = 5, y = 10;
    swapNum(x, y);
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    return 0;
}