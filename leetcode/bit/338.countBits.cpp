#include <iostream>
#include <vector>
using namespace std;

int countBit(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

vector<int> countBits(int num) {
    vector<int> res(num + 1);
    for (int i = 0; i <= num; i++) {
        res[i] = countBit(i);
    }
    return res;
}

// ��̬�滮 + �����Чλ
vector<int> countBits(int num) {
    vector<int> res(num + 1);
    for (int i = 0; i <= num; i++) {
        res[i] = res[i >> 1] + (i & 1);
    }
    return res;
}

// ��̬�滮 + �������λ
// �������һ��λ1 i & (i - 1) ������õ�֮ǰ�����˵Ľ�� + 1

vector<int> countBits(int num) {
    vector<int> res(num + 1);
    for (int i = 1; i <= num; i++) {
        res[i] = res[i & (i - 1)] + 1;
    }
    return res;
}

// ��̬�滮 + �����Чλ
// ������ǰ��������� + 1 > �õ����ڽ�������λ
// P(x+b)=P(x)+1,b=2^m >x
