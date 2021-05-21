#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int cap;
    // ˫����װ��(key, value)Ԫ��
    list<pair<int, int>> cache;
    // ��ϣ��keyӳ�䵽(key, value)��cache�е�λ��
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = map.find(key);
        // ���ʵ� key ������
        if (it == map.end()) return -1;
        // key ���ڣ���(k, v)������ͷ
        pair<int, int> kv = *map[key];
        cache.erase(map[key]);
        cache.push_front(kv);
        // ���� (key, value) ��cache�е�λ��
        map[key] = cache.begin();

        return kv.second; // value
    }
    
    void put(int key, int value) {
        // ���ж� key �Ƿ��Ѿ�����
        auto it = map.find(key);
        if (it == map.end()) {
            // key �����ڣ��ж�cache�Ƿ�����
            if (cache.size() == cap) {
                // cache ������ɾ��β���ļ�ֵ����λ��
                // ע��cache��map�е����ݶ�Ҫɾ��
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                map.erase(lastKey);
                cache.pop_back();
                // ������ (key, value) ����cache��ͷ
                cache.push_front(make_pair(key, value));
                map[key] = cache.begin();
            } else {
                // cache û����ֱ�����
                cache.push_front(make_pair(key, value));
                map[key] = cache.begin();
            }
        } else {
            // key ���ڣ�����value��������ͷ
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

// ��ϣ + ˫������
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


// ��ϣ + ˫������
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

    // ɾ���ڵ�
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

    // ��ͷ������һ���ڵ�
    void push_front(int key, int value) {
        DulNode* node = new DulNode(key, value);
        node -> next = head;
        head = node;
        if (!tail) tail = node;
        map[key] = node;
        ++size;
    }

    // ��β��ɾ���ڵ�
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
        // ֵ���ڣ��������е�λ����ǰ
        DulNode* node = map[key];
        int value = node -> val;
        delete_node(node);
        push_front(key, value);
        return value;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // ֵ���ڣ��޸�ֵ����λ����ǰ
            DulNode* node = map[key];
            delete_node(node);
            push_front(key, value);
        } else {
            // ֵ������
            // cache����
            if (size == cap) {
                // ��ɾ��β���ڵ�
                pop_back();
            }
            // ��ͷ�������½ڵ�
            push_front(key, value);
        }
    }
};


// ʵ��˫������
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