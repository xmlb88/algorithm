#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public:
    // ����洢Ԫ�ص�ֵ
    vector<int> nums;
    // ��ϣ���¼Ԫ�ص�����
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

        // ��Ԫ�ؽ���������ĩβ��pop_back
        // ��Ҫ����������
        int change_index = valToIndex[val];
        // β��Ԫ�ص�ֵ
        int last = nums.back();
        // ��������λ��
        swap(nums[change_index], nums.back());
        // �޸�valToIndex
        valToIndex[last] = change_index;
        // ����ɾ��pop
        nums.pop_back();
        // valToIndexɾ��
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