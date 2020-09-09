#include<iostream>
#include<vector>
using namespace std;


// ����a ��k �η��Ľ��

int mypow(int a, int k);

// �����������
int superPow(int a, vector<int>& b) {
    // �ݹ��base case
    if (b.empty()) return 1;

    // ȡ�����һ����
    int last = b.back();
    b.pop_back();

    // ��ԭ���⻯����С��ģ�ݹ����
    int part1 = mypow(a, last);
    int part2 = mypow(superPow(a, b), 10);

    // �ϲ������
    return part1 * part2;
}

// ����mod����
// (a * b) % k = (a % k)(b % k) % k
int base = 1337;
// ����a��k�η�Ȼ����base��ģ�Ľ��
int mypow(int a, int k) {
    // ��������ģ
    a %= base;
    int res = 1;
    for (int i = 0; i < k; i++) {
        // �˷����ܻ����
        res *= a;
        // �Գ˷������ģ
        res %= base;
    }

    return res;
}

int superPow(int a, vector<int>& b) {
    if (b.empty()) return 1;
    int last = b.back();
    b.pop_back();

    int part1 = mypow(a, last);
    int part2 = mypow(superPow(a, b), 10);

    // ÿ�γ˷�ȡģ
    return (part1 * part2) % base;
}

