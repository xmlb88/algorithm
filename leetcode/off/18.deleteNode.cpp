#include <iostream>
#include "list/listNode.h"
using namespace std;

ListNode* deleteNode(ListNode* head, int val) {
    if (head -> val == val) return head -> next;
    ListNode* cur = head;
    ListNode* pre;
    while (cur -> val != val) {
        pre = cur;
        cur = cur -> next;
    }
    pre -> next = cur -> next;
    return head;
}