#include <iostream>
#include <vector>
using namespace std;

bool exist(const vector<int>& vec, int target) {
    for (auot it = vec.begin(); it != vec.end(); ++it) {
        if (*it == target) {
            return true;
        }
    }
    return false;
}

// 9_5:
vector<int>::const_iterator exist(const vector<int>& vec, int target) {
    for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
        if (*it == target) {
            return it;
        }
    }
    return vec.cend();
}