#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// 暴力法 哈希/set
// 时间O(n)  空间O(n)
bool isUnique(string str) {
    unordered_set<char> set;
    for (int i = 0; i < str.size(); i++) {
        if (set.count(str[i])) return false;
        set.insert(str[i]);
    }
    return true;
}

// 