#include <iostream>
#include "list/listNode.h"
using namespace std;

ListNode* partition(ListNode* head, int x) {
    ListNode* before = new ListNode(0);
    ListNode* before_cur = before;
    ListNode* after = new ListNode(0);
    ListNode* after_cur = after;

    while (head) {
        if (head -> val < x) {
            before_cur -> next = head;
            before_cur = head;
            head = head -> next;
        } else {
            after_cur -> next = head;
            after_cur = head;
            head = head -> next;
        }
    }

    before_cur -> next = after -> next;
    after_cur -> next = nullptr;
    head = before -> next;
    delete(before);
    delete(after);
    return head;
}

