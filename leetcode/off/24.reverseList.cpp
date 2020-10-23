#include <iostream>
#include "listNode.h"
using namespace std;


// µü´ú
ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* cur = head;
    ListNode* node;
    while (cur) {
        node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }
    return pre;
}

// µÝ¹é
ListNode* reverseList(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;

    ListNode* newHead = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return newHead;
}