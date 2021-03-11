#include <iostream>
#include <iterator>
using namespace std;

void print(const char *cp) {
    if (cp) {
        while (*cp)
            cout << *cp++;
    }
}

void print(const int *beg, const int *end) {
    while (beg != end)
        cout << *beg++ << " ";
}

void print(const int ia[], size_t size) {
    for (size_t i = 0; i != size; ++i) {
        cout << ia[i] << " ";
    }
}

void print(int (&arr)[10]) {
    for (auto elem : arr) {
        cout << elem << " ";
    }
}

void print(int (*matrix)[10], int rowSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // ���鲻��������ʹ������ʱͨ��ת����ָ��
    // ������ֵ���ݵķ�ʽ�������飬�����԰��β�д�������������ʽ
    // void print(const int*);
    // void print(cosnt int[]);
    // void print(cosnt int[10]);

    // ʹ��ָ���βΣ�Ӧ���ṩ������Ϣ���鳤��
    // ���ָ�����鳤��
    char c[] = "this is a char array";
    print(c);
    cout << "\n====================" << endl;

    print(begin(a), end(a));
    cout << "\n====================" << endl;

    print(a, end(a) - begin(a));
    cout << "\n====================" << endl;

    print(a);
    cout << "\n====================" << endl;

    int b[][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
        {11, 22, 33, 44, 55, 66, 77, 88, 99, 100},
    };

    print(b, 3);
    cout << "\n====================" << endl;
}