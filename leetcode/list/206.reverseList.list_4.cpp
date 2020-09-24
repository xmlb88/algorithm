#include <iostream>
#include "listNode.h"
using namespace std;

// µü´ú
ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* cur = head;
    while (cur != NULL) {
        ListNode* node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }
    return pre;
}

// µÝ¹é
ListNode* reverseList(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;
    ListNode* last = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return last;
}




// review
ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* cur = head;

    while (cur) {
        ListNode* node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }
    return pre;
}

ListNode* reverseList(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;

    ListNode* node = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return node;
}