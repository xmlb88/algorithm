#include <iostream>
#include "listNode.h"
using namespace std;

// µÝ¹é
ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;

    ListNode *cur = head;
    ListNode *node = cur -> next;
    cur -> next = swapPairs(node -> next);
    node -> next = cur;
    return node;
}

// µü´ú
ListNode* swapPairs(ListNode* head) {
    if (!head || !head -> next) return head;
    ListNode* cur = head;
    ListNode* newHead = head -> next;
    ListNode* pre = new ListNode(0);
    pre -> next = head;
    while (cur && cur -> next) {
        ListNode* node = cur -> next;
        cur -> next = node -> next;
        node -> next = cur;
        pre -> next = node;
        pre = cur;
        cur = cur -> next;
    }
    return newHead;
}