#include <iostream>
#include "listNode.h"
using namespace std;

ListNode* insertionSortList(ListNode* head) {
    if (!head || !head -> next) return head;
    ListNode* tail = head;
    ListNode* sort = head -> next;
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;

    while (sort) {
        if (sort -> val < tail -> val) {
            ListNode* pos = dummy;
            while (pos -> next -> val < sort -> val) pos = pos -> next;
            tail -> next = sort -> next;
            sort -> next = pos -> next;
            pos -> next = sort;
            sort = tail -> next;
        } else {
            sort = sort -> next;
            tail = tail -> next;
        }
    }

    return dummy -> next;
}