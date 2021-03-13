#include <iostream>
#include <array>
#include <string>
using namespace std;

int main() {
    array<int, 42> arr;
    cout << arr.size() << " " << arr.max_size() << endl;
    array<string, 10> str;
    cout << str.size() << " " << str.max_size() << endl;
    

    array<int, 10> ia1;
    for (auto a : ia1) {
        cout << a << " ";
    }
    cout << "\n==============" << endl;
    array<int, 10> ia2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto a : ia2) {
        cout << a << " ";
    }
    cout << "\n==============" << endl;
    array<int, 10> ia3 = {42};
    for (auto a : ia3) {
        cout << a << " ";
    }
    cout << "\n==============" << endl;


    // array�ɽ��п��������ֵ����������������ƥ��
    int digs[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int cpy[10] = digs; // �����������鲻֧�ֿ�����ֵ
    array<int, 10> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 10> copy = digits;   // ��ȷ��ֻҪ��������ƥ�伴�Ϸ�
}