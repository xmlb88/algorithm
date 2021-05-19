#include <iostream>
#include <time.h>
using namespace std;

void QuickSort(int* h, int left, int right) {
    if (h == NULL) return;
    if (left >= right) return;

    srand(time(NULL));
    int len = right - left + 1;
    int kindex = rand() % len + left;
    swap(h[left], h[kindex]);

    int key = h[left], i = left, j = right;
    while (i < j) {
        while (h[j] >= key && i < j) --j;
        if (i < j) h[i] = h[j];
        while (h[i] < key && i < j) ++i;
        if (i < j) h[j] = h[i];
    }

    h[i] = key;
    QuickSort(h, left, i - 1);
    QuickSort(h, j + 1, right);
}