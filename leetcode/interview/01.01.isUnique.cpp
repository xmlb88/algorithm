#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// ������ ��ϣ/set
// ʱ��O(n)  �ռ�O(n)
bool isUnique(string str) {
    unordered_set<char> set;
    for (int i = 0; i < str.size(); i++) {
        if (set.count(str[i])) return false;
        set.insert(str[i]);
    }
    return true;
}

// 