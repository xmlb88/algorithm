#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class TwoSum {
public:
    /** Initialize your data structure here. */
    unordered_map<long, int> m;
    TwoSum() {

    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        m[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto [val, count] : m) {
            long target = value - val;
            if (target == val) {
                if (m[val] > 1) return true;
            }
            else {
                if (m.find(target) != m.end()) return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */