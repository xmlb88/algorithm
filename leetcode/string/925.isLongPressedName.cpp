#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isLongPressedName(string name, string typed) {
    int i = 0, j = 0;
    while (i < name.size() && j < typed.size()) {
        if (name[i] != typed[j]) return false;
        int count_i = 0;
        char alpha_i = name[i];
        while (name[i] == alpha_i) {
            count_i++;
            i++;
        }

        int count_j = 0;
        char alpha_j = typed[j];
        while (typed[j] == alpha_j) {
            count_j++;
            j++;
        }

        if (count_j < count_i) return false;
    }

    if (i == name.size() && j == typed.size()) return true;
    else return false;
}

// 双指针 不用计算个数
bool isLongPressedName(string name, string typed) {
    int i = 0, j = 0;
    while (j < typed.size()) {
        if (i < name.size() && name[i] == typed[j]) {
            i++, j++;
        } else if (j > 0 && typed[j] == typed[j - 1]) {
            j++;
        } else return false;
    }
    return i == name.size();
}