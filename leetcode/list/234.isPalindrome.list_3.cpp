#include <iostream>
#include "listNode.h"
using namespace std;

// 递归后序判断
ListNode* left;
bool isPalindrome(ListNode* head) {
    left = head;
    return palind(head);
}

bool palind(ListNode* head) {
    if (head == NULL) return true;

    bool res = palind(head -> next);
    res = res && (head -> val == left -> val);
    left = left -> next;
    return res;
}

// 反转后半段后进行对比
bool isPalindrome(ListNode* head) {
    if (head == NULL || head -> next == NULL) return true;

    ListNode* fast = head;
    ListNode* slow = head;
    
    while (fast && fast -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    if (fast != NULL) {
        slow = slow -> next;
    }

    ListNode* pre = NULL;
    ListNode* cur = slow;

    while (cur != NULL) {
        ListNode* node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }

    ListNode* left = head;
    ListNode* right = pre;

    while (right != NULL) {
        if (left -> val != right -> val)
            return false;
        right = right -> next;
        left = left -> next;
    }
    return true;
}

1 2 3 4 5
1 2 3 4 5 6