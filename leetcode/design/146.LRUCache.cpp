#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int cap;
    // 双链表，装着(key, value)元组
    list<pair<int, int>> cache;
    // 哈希表，key映射到(key, value)在cache中的位置
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = map.find(key);
        // 访问的 key 不存在
        if (it == map.end()) return -1;
        // key 存在，把(k, v)换到队头
        pair<int, int> kv = *map[key];
        cache.erase(map[key]);
        cache.push_front(kv);
        // 更新 (key, value) 在cache中的位置
        map[key] = cache.begin();

        return kv.second; // value
    }
    
    void put(int key, int value) {
        // 先判断 key 是否已经存在
        auto it = map.find(key);
        if (it == map.end()) {
            // key 不存在，判断cache是否已满
            if (cache.size() == cap) {
                // cache 已满，删除尾部的键值对腾位置
                // 注意cache和map中的数据都要删除
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                map.erase(lastKey);
                cache.pop_back();
                // 需插入的 (key, value) 加在cache队头
                cache.push_front(make_pair(key, value));
                map[key] = cache.begin();
            } else {
                // cache 没满，直接添加
                cache.push_front(make_pair(key, value));
                map[key] = cache.begin();
            }
        } else {
            // key 存在，更改value并换到队头
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


