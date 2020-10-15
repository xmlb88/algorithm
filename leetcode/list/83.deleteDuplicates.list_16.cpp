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