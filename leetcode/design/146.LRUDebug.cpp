#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct DulNode {
    int key;
    int val;
    DulNode* pre;
    DulNode* next;
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

    void delete_node(DulNode* node) {
        if (!node) return;
        DulNode* pre_node = node -> pre;
        DulNode* next_node = node -> next;
        if (pre_node) pre_node -> next = next_node;
        if (next_node) next_node -> pre = pre_node;
        if (node == head) head = next_node;
        if (node == tail) tail = pre_node;
        map.erase(node -> key);
        delete node;
        --size;
    }

    void push_front(int key, int value) {
        DulNode* node = new DulNode(key, value);
        node -> next = head;
        if (head) head -> pre = node;
        head = node;
        if (!tail) tail = node;
        map[key] = node;
        ++size;
    }

    void pop_back() {
        if (!tail) return;
        DulNode* pre_node = tail -> pre;
        if (pre_node) pre_node -> next = nullptr;
        map.erase(tail -> key);
        if (head == tail) head = pre_node;
        delete tail;
        tail = pre_node;
        --size;
    }

    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        DulNode* node = map[key];
        int value = node -> val;
        delete_node(node);
        push_front(key, value);
        print();
        return value;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            DulNode* node = map[key];
            delete_node(node);
            push_front(key, value);
        } else {
            if (cap == size) {
                pop_back();
            }
            push_front(key, value);
        }
        print();
    }

    void print() {
        DulNode* cur = head;
        while (cur) {
            cout << "<" << cur -> key << ", " << cur -> val << "> ";
            cur = cur -> next;
        }
        cout << endl;
    }
};

int main() {
    LRUCache lc = LRUCache(2);
    lc.put(1, 1);
    lc.put(2, 2);
    cout << lc.get(1) << endl;
    lc.put(3, 3);
    cout << lc.get(2) << endl;
    lc.put(4, 4);
    cout << lc.get(1) << endl;
    cout << lc.get(3) << endl;
    cout << lc.get(4) << endl;
}