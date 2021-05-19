#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

// ������
// �󶥶ѣ���С��������
void AdjustHeap(int* h, int node, int len) {
    int index = node;
    int child = 2 * index + 1;  // ����
    while (child < len) {
        if (child + 1 < len && h[child] < h[child + 1]) {
            child++;
        }

        if (h[index] >= h[child]) break;
        swap(h[child], h[index]);
        index = child;
        child = 2 * index + 1;
    }
}

// ����
void MakeHeap(int* h, int len) {
    for (int i = len / 2; i >= 0; --i) {
        AdjustHeap(h, i, len);
    }
}

// ����
void HeapSort(int* h, int len) {
    MakeHeap(h, len);
    for (int i = len - 1; i >= 0; --i) {
        swap(h[i], h[0]);
        AdjustHeap(h, 0, i);
    }
}

int main() {
    int A[10] = {0};
    srand(time(NULL));
    cout << "before:\n";
    for (int i = 0; i < 10; ++i) {
        A[i] = rand() % 100;
        printf("%d ", A[i]);
    }
    printf("\n");
    cout << "after:\n";
    HeapSort(A, 10);
    for (int i = 0; i < 10; ++i) {
        cout << A[i] << " ";
    }
}