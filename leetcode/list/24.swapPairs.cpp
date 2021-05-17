#include <iostream>
#include "listNode.h"
using namespace std;

// 递归
ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;

    ListNode *cur = head;
    ListNode *node = cur -> next;
    cur -> next = swapPairs(node -> next);
    node -> next = cur;
    return node;
}

// 迭代
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

// review 2021年5月17日11:03:36
ListNode* swapPairs(ListNode* head) {
    if (!head || !head -> next) return head;

    ListNode* cur = head;
    ListNode* nxt = head -> next;
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    ListNode* pre = dummy;
    while (cur && nxt) {
        pre -> next = nxt;
        cur -> next = nxt -> next;
        nxt -> next = cur;
        pre = cur;
        cur = cur -> next;
        if (!cur) break;
        nxt = cur -> next;
    }
    return dummy -> next;
}

// 递归
ListNode* swapPairs(ListNode* head) {
    if (!head || !head -> next) return head;

    ListNode* cur = head;
    ListNode* nxt = head -> next;
    cur -> next = swapPairs(nxt -> next);
    nxt -> next = cur;
    return nxt;
}

// 迭代
ListNode* swapPairs(ListNode* head) {
    if (!head || !head -> next) return head;
    ListNode* cur = head;
    ListNode* newHead = head -> next;
    ListNode* pre = new ListNode(0);
    pre -> next = head;

    while (cur && cur -> next) {
        ListNode* nxt = cur -> next;
        pre -> next = nxt;
        cur -> next = nxt -> next;
        nxt -> next = cur;
        pre = cur;
        cur = cur -> next;
    }

    return newHead;
}