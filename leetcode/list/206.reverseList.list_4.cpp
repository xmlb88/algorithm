#include <iostream>
#include "listNode.h"
using namespace std;

// ����
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

// �ݹ�
ListNode* reverseList(ListNode* head) {
    if (root == NULL || head -> next == NULL) return head;
    ListNode* last = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return last;
}

