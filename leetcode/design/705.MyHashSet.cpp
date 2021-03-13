#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

class MyHashSet {
public:
    vector<bool> m;
    /** Initialize your data structure here. */
    MyHashSet() {

    }
    
    void add(int key) {
        if (key >= m.size()) {
            m.resize(key + 1, false);
        }
        m[key] = true;
    }
    
    void remove(int key) {
        if (key < m.size()) {
            m[key] = false;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if (key >= m.size()) return false;
        return m[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

// 链地址法处理冲突
// base 取质数，769
class MyHashSet {
private:
    vector<list<int>> data;
    static const int base = 769;
    static int hash(int key) {
        return key % base;
    }

public:
    MyHashSet():data(base) {}

    void add(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it) {
            if ((*it) == key) return;
        }
        data[h].push_back(key);
    }

    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it) {
            if ((*it) == key) {
                data[h].erase(it);
                return;
            }
        }
    }

    bool contains(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it) {
            if ((*it) == key) {
                return true;
            }
        }
        return false;
    }
};