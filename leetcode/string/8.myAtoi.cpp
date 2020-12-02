#include <iostream>
#include <string>
using namespace std;

int myAtoi(string s) {
    int i = 0, flag = 1;
    // ȥ����ͷ�Ŀո�
    while (s[i] == ' ') {
        i++;
    }

    // ����+-��
    if (s[i] == '-') {
        flag = -1;
    }
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    int res = 0;
    while (isdigit(s[i])) {
        int n = s[i] - '0';
        if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && n > INT_MAX % 10)) {
            return flag > 0 ? INT_MAX : INT_MIN;
        }
        res = res * 10 + n;
        i++;
    }

    return flag > 0 ? res : -res;
}