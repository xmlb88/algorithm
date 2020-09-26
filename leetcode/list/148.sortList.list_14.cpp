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
ListNode* cut(ListNode* head, int n) {
    ListNode* p = head;
    while (n > 1 && p) {
        n--;
        p = p -> next;
    }

    if (p == NULL) {
        return NULL;
    }

    ListNode* node = p -> next;
    p -> next = NULL;
    return node;
}

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (l1 && l2) {
        if (l1 -> val < l2 -> val) {
            cur -> next = l1;
            l1 = l1 -> next;
            cur = cur -> next;
        } else {
            cur -> next = l2;
            l2 = l2 -> next;
            cur = cur -> next;
        }
    }

    if (l1) cur -> next = l1;
    if (l2) cur -> next = l2;
    return dummy -> next;
}

ListNode* sortList(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;
    int length = 0;
    ListNode* p = head;
    // 先求链表长度，然后根据长度来cut
    while (p) {
        length++;
        p = p -> next;
    }

    // 第一次cut1，然后根据归并的思路，cut的大小依次*2，
    // 边界条件size < length, 因为size == n表示的是链表的每个长度为n的段已经是有序的
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    for (int size = 1; size < length; size *= 2) {
        ListNode* cur = dummy -> next;
        ListNode* tail = dummy;
        while (cur) {
            ListNode* left = cur;
            ListNode* right = cut(left, size);
            cur = cut(right, size);
            tail -> next = merge(left, right);
            while (tail -> next) {
                tail = tail -> next;
            }
        }
    }
    return dummy -> next;
}

ListNode* cut(ListNode* head, int n) {
    ListNode* p = head;
    while (p && n > 1) {
        p = p -> next;
        n--;
    }

    if (p == NULL) return NULL;
    ListNode* node = p -> next;
    p -> next = NULL;
    return node;
}

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (l1 && l2) {
        if (l1 -> val < l2 -> val) {
            cur -> next = l1;
            l1 = l1 -> next;
            cur = cur -> next;
        } else {
            cur -> next = l2;
            l2 = l2 -> next;
            cur = cur -> next;
        }
    }

    cur -> next = l1 ? l1 : l2;
    return dummy -> next;
}

ListNode* sortList(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;

    // 先求长度
    ListNode* node = head;
    int length = 0;
    while (node) {
        node = node -> next;
        length++;
    }

    // 分段cut再merge
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    for (int size = 1; size < length; size *= 2) {
        ListNode* tail = dummy;
        ListNode* cur = dummy -> next;
        while (cur) {
            ListNode* left = cur;
            ListNode* right = cut(left, size);
            cur = cut(right, size);
            tail -> next = merge(left, right);
            while (tail -> next) {
                tail = tail -> next;
            }
        }
    }

    return dummy -> next;
}