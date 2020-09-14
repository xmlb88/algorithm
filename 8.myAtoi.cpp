#include<iostream>
#include<string>
#include<vector>
using namespace std;

int myAtoi(string str) {
    int i = 0;
    int flag = 1;

    while (str[i] == ' ') {
        i++;
    }

    if (str[i] == '-') {
        flag = -1;
    }

    if (str[i] == '+' || str[i] == '-') {
        i++;
    }

    int res = 0;
    while (isdigit(str[i])) {
        int n = str[i] - '0';
        if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && n > INT_MAX % 10)) {
            return flag > 0? INT_MAX : INT_MIN;
        }

        res = res * 10 + n;
        i++;
    }

    return flag > 0? res : -res;
}