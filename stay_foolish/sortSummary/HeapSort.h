#include <iostream>
using namespace std;

// 调整
// 大顶堆，sort之后升序
void AdjustHeap(int* h, int index, int len) {
    int child = 2 * index + 1;
    if (child < len) {
        if (child + 1 < len && h[child] < h[child + 1]) {
            ++child;
        }

        if (h[index] < h[child]) {
            swap(h[index], h[child]);
            AdjustHeap(h, child, len);
        }
    }
}

// 建堆，只需一次
void MakeHeap(int* h, int len) {
    for (int i = len / 2; i >= 0; --i) {
        AdjustHeap(h, i, len);
    }
}

// 排序
void HeapSort(int* h, int len) {
    MakeHeap(h, len);
    for (int i = len - 1; i >= 0; --i) {
        swap(h[0], h[i]);
        AdjustHeap(h, 0, i);
    }
}