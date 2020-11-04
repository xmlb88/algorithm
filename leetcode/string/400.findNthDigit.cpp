#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findNthDigit(int n) {
    string s = "0";
    for (int i = 1; i <= 220000; i++) {
        s += to_string(i);
    }
    return s[n] - '0';
}

int findNthDigit(int n) {
    long base = 9, digits = 1;
    while (n - base * digits > 0) {
        n -= base * digits;
        base *= 10;
        digits++;
    }

    int idx = n % digits;
    if (idx == 0) idx = digits;
    long number = 1;
    for (int i = 1; i < digits; i++) {
        number *= 10;
    }
    number += (idx == digits) ? n / digits - 1 : n / digits;

    for (int i = idx; i < digits; i++) number /= 10;
    return number % 10;
}

int findNthDigit(int n) {
    // bit ��¼���������λ����p��¼��������ĳ���
    long long bit = 1, p = 9;
    while (n - bit * p > 0) {
        n -= bit * p;
        bit++;
        p *= 10;
    }

    // num �Ǵ���������
    int num = pow(10, bit - 1) + (n - 1) / bit;

    // pos �Ǵ���num�е�λ��
    int pos = n % bit;
    pos = pos == 0 ? bit : pos;
    int t = pow(10, bit - pos);
    return num / t % 10;
}