#include <iostream>
#include <vector>
#include "listNode.h"
using namespace std;

ListNode* cur;
bool isPalindrome(ListNode* head) {
    cur = head;
    return isPalind(head);
}

bool isPalind(ListNode* head) {
    if (head == NULL) return true;
    bool res = isPalind(head -> next);
    res = res && (head -> val == cur -> val);
    cur = cur -> next;
    return res;
}

// 
bool isPalindrome(ListNode* head) {
    if (!head || !head -> next) return true;
    ListNode *fast = head, *slow = head;
    while (fast -> next != NULL && fast -> next -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    ListNode* second = slow -> next;

    // 反转后半段
    ListNode* cur = second;
    ListNode* pre = NULL;
    ListNode* node;
    while (cur) {
        node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }

    // 比较
    ListNode* newHead = pre;
    while (newHead) {
        if (newHead -> val != head -> val) return false;
        head = head -> next;
        newHead = newHead -> next;
    }
    return true;
}
1 2 3 4
1 2 3 4 5