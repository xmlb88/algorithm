#include <iostream>
#include "listNode.h"
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL) return NULL;

    ListNode *slow = head, *fast = head;

    while (fast != NULL) {
        if (fast -> val != slow -> val) {
            slow -> next = fast;
            slow = slow -> next;
        }
        fast = fast -> next;
    }
    slow -> next = NULL;
    return head;
}


// review 2021Äê3ÔÂ26ÈÕ09:11:55
ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head -> next) return head;
    ListNode* curr = head;
    while (curr && curr -> next) {
        if (curr -> val == curr -> next -> val) {
            curr -> next = curr -> next -> next;
        } else {
            curr = curr -> next;
        }
    }
    return head;
}


ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head -> next) return head;

    if (head -> val != head -> next -> val) {
        head -> next = deleteDuplicates(head -> next);
    } else {
        ListNode* move = head -> next;
        while (move && move -> val == head -> val) {
            move = move -> next;
        }
        head -> next = deleteDuplicates(move);
    }
    return head;
}