#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    ListNode* cur = dummy;
    while (cur -> next != NULL) {
        if (cur -> next -> val == val) {
            // ListNode* tmp = cur -> next;
            cur -> next = cur -> next -> next;
            // delete tmp;
        }
        else cur = cur -> next;
    }
    return dummy -> next;
}


ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    ListNode* cur = dummy;
    while (cur -> next) {
        if (cur -> next -> val == val) {
            cur -> next = cur -> next -> next;
        }
        else cur = cur -> next;
    }
    return dummy -> next;
}