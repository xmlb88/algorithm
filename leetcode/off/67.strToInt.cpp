#include <iostream>
#include <string>
using namespace std;

int strToInt(string str) {
    int i = 0, flag = 1;

    while (str[i] == ' ') {
        i++;
    }

    if (str[i] == '+') {
        i++;
    } else if (str[i] == '-') {
        flag = -1;
        i++;
    }

    int res = 0;
    while (isdigit(str[i])) {
        int n = str[i] - '0';
        if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && n > INT_MAX % 10)) {
            return flag > 0 ? INT_MAX : INT_MIN;
        }
        res = res * 10 + n;
        i++;
    }
    return flag > 0 ? res : -res;
}