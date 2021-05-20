#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr) {}
    ListNode(int x):val(x), next(nullptr) {}
    ListNode(int x, ListNode* next):val(x), next(next) {}
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    ListNode* head;
    MyLinkedList() {
        head = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int i = 0;
        ListNode* cur = head;
        while (cur && i < index) {
            cur = cur -> next;
            ++i;
        }
        if (cur) return cur -> val;
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* p = new ListNode(val);
        p -> next = head;
        head = p;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (head == nullptr) {
            head = new ListNode(val);
            return;
        }
        ListNode* cur = head;
        while (cur -> next) {
            cur = cur -> next;
        }
        cur -> next = new ListNode(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
            return;
        }

        int i = 0;
        ListNode* cur = head;
        while (cur && i < index - 1) {
            cur = cur -> next;
            ++i;
        }

        if (cur) {
            ListNode* node = new ListNode(val);
            node -> next = cur -> next;
            cur -> next = node;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index == 0 && head != nullptr) {
            ListNode* del = head;
            head = head -> next;
            delete del;
            return;
        }

        int i = 0;
        ListNode* cur = head;
        while (cur && i < index - 1) {
            cur = cur -> next;
            ++i;
        }

        if (!cur) return;
        if (cur -> next) {
            ListNode* del = cur -> next;
            cur -> next = del -> next;
            delete del;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */