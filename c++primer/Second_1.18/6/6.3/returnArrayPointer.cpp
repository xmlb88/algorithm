#include <iostream>
#include <string>
using namespace std;

// ʹ��β�÷�������
auto func(int i) -> int(*)[10];

// ʹ��decltype
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) *arrPtr(int i) {
    return (i % 2) ? &odd : &even;
}

// 6-36
string (&func())[10];

// ���ͱ���
typedef string arrs[10];
arrs& func();

// β��
auto func() -> string(&)[10];

// decltype
string s[10];
decltype(s)& func();

int main() {
    // typedef int arrT[10];
    // using arrT = int[10];
    // arrT* func(int i);

    // int arr[10];
    // int *p1[10];
    // int (*p2)[10] = &arr;

    // arrT a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // for (auto v : a) {
    //     cout << v << " ";
    // }
    for (auto i : *arrPtr(1)) {
        cout << i << " ";
    }
}