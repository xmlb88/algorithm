#include <iostream>
#include <string>
#include <vector>
using namespace std;

using F = int (int*, int); // ��������
using PF = int (*)(int*, int); // ָ������

PF f1(int); // ��ȷ
F f1(int); // ����
F *f1(int); // ��ȷ

// ֱ������
int (*f1(int))(int*, int);

// β��
auto f1(int) -> int (*)(int*, int);

int (int* p, int i) {
    return *p * i;
}

// 6_54:
int func(int, int);
typedef int (*pf)(int, int);
using f1 = int(int, int);
vector<int(*)(int, int)> vec = {func};
vector<decltype(func)*> vec;
vector<pf> vec;
vector<f1*> vec;
