#include <iostream>
#include "list/listNode.h"
using namespace std;

ListNode* detectCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast && fast -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
        if (fast == slow) break;
    }

    if (!fast || !fast -> next) return nullptr;

    slow = head;
    while (slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }

    return slow;
}

// 1 2 2 1
// 1 2 3 2 1