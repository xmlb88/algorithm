#include <iostream>
using namespace std;

// λ����
int add(int a, int b) {
    while (b != 0) {
        int c = (unsigned int)(a & b) << 1; // ��λ = &���� ����һλ
        a ^= b; // �����ǽ�λ��
        b = c; // b = ��λ
    }
    return a;
}