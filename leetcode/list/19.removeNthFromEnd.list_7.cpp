#include <iostream>
#include "listNode.h"
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    for (int i = 0; i < n; i++) {
        fast = fast -> next;
    }

    while (fast != NULL && slow != NULL) {
        fast = fast -> next;
        slow = slow -> next;
    }

    slow -> next = slow -> next -> next;
    return dummy -> next;
}