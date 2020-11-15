#include <iostream>
#include "list/listNode.h"
using namespace std;

int kthToLast(ListNode* head, int k) {
    ListNode *fast = head, *slow = head;
    for (int i = 0; i < k; i++) {
        fast = fast -> next;
    }

    while (fast) {
        fast = fast -> next;
        slow = slow -> next;
    }

    return slow -> val;
}