#include <iostream>
#include <string>
using namespace std;

// own thought
string printBin(double num) {
    if (num >= 1 || num <= 0) return "ERROR";

    string res = "0.";
    while (res.length() <= 32 && num > 0) {
        if (num * 2 >= 1) {
            res += '1';
            num = num * 2 - 1;
        } else {
            res += '0';
            num *= 2;
        }
    }
    return num == 0 ? res : "ERROR";
}

string printBin(double num) {
    string res = "0.";
    while (res.length() <= 32 && num != 0) {
        if (num * 2 >= 1) {
            res += '1';
            num = num * 2 - 1;
        } else {
            res += '0';
            num *= 2;
        }
    }
    return num == 0 ? res : "ERROR";
}


// 方法1
string printBin(double num) {
    if (num >= 1 || num <= 0) return "ERROR";

    string res = "0.";
    while (num > 0) {
        if (res.length() > 32) return "ERROR";
        double r = num * 2;
        if (r >= 1) {
            res += '1';
            num = r - 1;
        } else {
            res += '0';
            num = r;
        }
    }
    return res;
}

// 方法2
string printBin(double num) {
    if (num >= 1 || num <= 0) return "ERROR";

    string res = "0.";
    double frac = 0.5;
    while (num > 0) {
        if (res.length() > 32) return "ERROR";

        if (num >= frac) {
            res += '1';
            num -= frac;
        } else {
            res += '0';
        }

        frac /= 2;
    }

    return res;
}