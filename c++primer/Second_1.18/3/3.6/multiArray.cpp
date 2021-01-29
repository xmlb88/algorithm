#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    for (auto p = ia; p != ia + 3; ++p) {
        for (auto q = *p; q != *p + 4; ++q) {
            cout << *q << ' ';
        }
        cout << endl;
    }
    cout << "==================1" << endl;

    for (auto p = begin(ia); p != end(ia); ++p) {
        for (auto q = begin(*p); q != end(*p); ++q) {
            cout << *q << ' ';
        }
        cout << endl;
    }
    cout << "==================2" << endl;

    for (const auto &row : ia) {
        for (auto col : row) {
            cout << col << ' ';
        }
        cout << endl;
    }
    cout << "==================3" << endl;

    // typedef int int_array[4];
    using int_array = int[4];
    for (int_array *p = ia; p != ia + 3; ++p) {
        for (int *q = *p; q != *p + 4; ++q) {
            cout << *q << ' ';
        }
        cout << endl;
    }
    cout << "==================4" << endl;

    int arr[3][4] = {
        {2, 4, 6, 8},
        {10, 12, 14, 16},
        {18, 20, 22, 24},
    };

    // range for 
    for (const int(&row)[4] : arr) {
        for (int col : row)
            cout << col << " ";
        cout << endl;
    }
    cout << "==================Range_for" << endl;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) 
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << "==================For_loop" << endl;

    for (int (*row)[4] = arr; row != arr + 3; ++row) {
        for (int *col = *row; col != *row + 4; ++col) {
            cout << *col << " ";
        }
        cout << endl;
    }
    cout << "==================Using_pointers" << endl;

}