#include <iostream>
#include <time.h>
#include "HeapSort.h"
#include "QuickSort.h"
using namespace std;

int main() {
    int A[10] = {0};
    srand(time(nullptr));
    cout << "before:" << endl;
    for (int i = 0; i < 10; ++i) {
        A[i] = rand() % 100;
        cout << A[i] << " ";
    }
    cout << endl;
    cout << "after:" << endl;
    // HeapSort(A, 10);
    QuickSort(A, 0, 9);
    for (int i = 0; i < 10; ++i) {
        cout << A[i] << " ";
    }
}