#include <iostream>
#include "listNode.h"
using namespace std;


// 递归解法
ListNode* sortList(ListNode* head) {
    // base case
    if (!head || !head -> next) return head;

    // 找到中间结点
    ListNode* fast = head -> next;
    ListNode* slow = head;
    while (fast && fast -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    // 断链
    ListNode* second = slow -> next;
    slow -> next = NULL;

    // 递归分开排序
    ListNode* left = sortList(head);
    ListNode* right = sortList(second);

    // 合并
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (left && right) {
        if (left -> val < right -> val) {
            cur -> next = left;
            left = left -> next;
        } else {
            cur -> next = right;
            right = right -> next;
        }
        cur = cur -> next;
    }

    if (left) cur -> next = left;
    if (right) cur -> next = right;

    return dummy -> next;
}

// 迭代  空间O(1)
ListNode* sortList(ListNode* head) {
    
}