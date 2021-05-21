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

// 哈希 + 双向链表
class LRUCache {
public:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        auto it = map[key];
        int value = it -> second;
        cache.erase(it);
        cache.push_front(make_pair(key, value));
        map[key] = cache.begin();
        return value;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            auto it = map[key];
            cache.erase(it);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        } else {
            if (cache.size() == cap) {
                auto del = cache.back();
                map.erase(del.first);
                cache.pop_back();
            }
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
    }
};


// 哈希 + 双向链表
struct DulNode {
    int key;
    int val;
    DulNode* pre;
    DulNode* next;
    DulNode() : key(0), val(0), pre(nullptr), next(nullptr) {}
    DulNode(int x, int y) : key(x), val(y), pre(nullptr), next(nullptr) {}
    DulNode(int x, int y, DulNode* _pre, DulNode* _next):
        key(x), val(y), pre(_pre), next(_next) {}
};

class LRUCache {
public:
    int cap, size = 0;
    DulNode *head = nullptr, *tail = nullptr;
    unordered_map<int, DulNode*> map;

    LRUCache(int capacity) {
        cap = capacity;
    }

    // 删除节点
    void delete_node(DulNode* node) {
        if (!node) return;
        DulNode* pre_node = node -> pre;
        DulNode* next_node = node -> next;
        if (pre_node) pre_node -> next = next_node;
        if (next_node) next_node -> pre = pre_node;
        map.erase(node -> key);
        delete node;
        --size;
    }

    // 在头部插入一个节点
    void push_front(int key, int value) {
        DulNode* node = new DulNode(key, value);
        node -> next = head;
        head = node;
        if (!tail) tail = node;
        map[key] = node;
        ++size;
    }

    // 在尾部删除节点
    void pop_back() {
        if (!tail) return;
        DulNode* pre_node = tail -> pre;
        if (pre_node) pre_node -> next = nullptr;
        map.erase(tail -> key);
        delete tail;
        tail = pre_node;
        --size;
    }

    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        // 值存在，在链表中的位置提前
        DulNode* node = map[key];
        int value = node -> val;
        delete_node(node);
        push_front(key, value);
        return value;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // 值存在，修改值并将位置提前
            DulNode* node = map[key];
            delete_node(node);
            push_front(key, value);
        } else {
            // 值不存在
            // cache已满
            if (size == cap) {
                // 先删除尾部节点
                pop_back();
            }
            // 在头部插入新节点
            push_front(key, value);
        }
    }
};


// 实现双向链表
struct DulNode {
    int key;
    int val;
    DulNode* pre;
    DulNode* next;
    DulNode() : key(0), val(0), pre(nullptr), next(nullptr) {}
    DulNode(int x, int y) : key(x), val(y), pre(nullptr), next(nullptr) {}
    DulNode(int x, int y, DulNode* _pre, DulNode* _next) :
        key(x), val(y), pre(_pre), next(_next) {}
};

class LRUCache {
public:
    int cap, size = 0;
    DulNode *head, *tail;
    unordered_map<int, DulNode*> map;

    LRUCache(int capacity) {
        cap = capacity;
        head = new DulNode();
        tail = new DulNode();
        head -> next = tail;
        tail -> pre = head;
    }

    void delete_node(DulNode* node) {
        DulNode* pre_node = node -> pre;
        DulNode* next_node = node -> next;
        pre_node -> next = next_node;
        next_node -> pre = pre_node;
        map.erase(node -> key);
        delete node;
        --size;
    }

    void push_front(int key, int value) {
        DulNode* node = new DulNode(key, value);
        DulNode* next_node = head -> next;
        node -> next = next_node;
        next_node -> pre = node;
        head -> next = node;
        node -> pre = head;
        map[key] = node;
        ++size;
    }

    void pop_back() {
        if (size == 0) return;
        DulNode* last_node = tail -> pre;
        DulNode* pre_node = last_node -> pre;
        pre_node -> next = tail;
        tail -> pre = pre_node;
        map.erase(last_node -> key);
        delete last_node;
        --size;
    }

    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        DulNode* node = map[key];
        int value = node -> val;
        delete_node(node);
        push_front(key, value);
        return value;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            DulNode* node = map[key];
            delete_node(node);
            push_front(key, value);
        } else {
            if (size == cap) {
                pop_back();
            }
            push_front(key, value);
        }
    }
};