#include <iostream>
#include "list/listNode.h"
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return nullptr;
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    int carry = 0;
    while (l1 || l2) {
        int value = carry;
        if (l1) {
            value += l1 -> val;
            l1 = l1 -> next;
        }

        if (l2) {
            value += l2 -> val;
            l2 = l2 -> next;
        }

        cur -> next = new ListNode(value % 10);
        cur = cur -> next;
        carry = value / 10;
    }

    if (carry) cur -> next = new ListNode(carry);

    return head -> next;
}