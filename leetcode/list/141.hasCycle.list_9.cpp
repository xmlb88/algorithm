#include <iostream>
#include "listNode.h"
using namespace std;

bool hasCycle(ListNode* head) {
    if (head == NULL) return false;

    ListNode* fast = head;
    ListNode* slow = head;

    while (fast ->next != NULL && fast != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
}

// review 2021Äê5ÔÂ20ÈÕ09:26:25
bool hasCycle(ListNode* head) {
    if (!head) return false;
    ListNode *fast = head, *slow = head;
    while (fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (fast == slow) return true;
    }

    return false;
}