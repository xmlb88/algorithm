#include <iostream>
#include "listNode.h"
using namespace std;

ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode *fast = head, *slow = head;
    while (k--) {
        fast = fast -> next;
    }

    while (fast) {
        fast = fast -> next;
        slow = slow -> next;
    }
    return slow;
}