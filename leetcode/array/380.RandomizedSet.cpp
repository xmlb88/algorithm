#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public:
    // 数组存储元素的值
    vector<int> nums;
    // 哈希表记录元素的索引
    unordered_map<int, int> valToIndex;

    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (valToIndex.count(val)) {
            return false;
        }
        valToIndex[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!valToIndex.count(val)) {
            return false;
        }

        // 将元素交换到数组末尾后pop_back
        // 需要交换的索引
        int change_index = valToIndex[val];
        // 尾部元素的值
        int last = nums.back();
        // 交换数组位置
        swap(nums[change_index], nums.back());
        // 修改valToIndex
        valToIndex[last] = change_index;
        // 数组删除pop
        nums.pop_back();
        // valToIndex删除
        valToIndex.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// TODO: