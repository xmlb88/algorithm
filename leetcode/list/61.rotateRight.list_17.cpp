#include <iostream>
#include "listNode.h"
using namespace std;

ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL || head -> next == NULL) return head;
    ListNode *cur = head;
    int count = 1;
    while (cur -> next != NULL) {
        cur = cur -> next;
        count++;
    }

    k = k % count;
    for (int i = k; i > 0; i--) {
        ListNode* last = head;
        while (last -> next -> next != NULL) {
            last = last -> next;
        }
        ListNode* lastNode = last -> next;
        lastNode -> next = head;
        last -> next = NULL;
        head = lastNode;
    }

    return head;
}

// official
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head -> next) return head;
    ListNode* cur = head;
    int length = 1;
    while (cur -> next) {
        cur = cur -> next;
        length++;
    }
    
    cur -> next = head;
    int step = length - (k % length) - 1;
    ListNode* node = head;
    while (step--) {
        node = node -> next;
    }

    ListNode* newHead = node -> next;
    node -> next = NULL;
    return newHead;
}

// review
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head -> next) return head;
    ListNode* cur = head;
    int length = 1;
    while (cur -> next) {
        cur = cur -> next;
        length++;
    }
    cur -> next = head;
    cur = head;
    int step = length - (k % length) - 1;
    while (step--) {
        cur = cur -> next;
    }
    ListNode* newHead = cur -> next;
    cur -> next = NULL;
    return newHead;
}


// review 2021年3月27日10:45:37
// own
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head -> next) return head;
    ListNode *fast = head, *slow = head;
    int size = 0;
    while (fast) {
        fast = fast -> next;
        ++size;
    }

    k = k % size;
    fast = head;
    for (int i = 0; i < k; ++i) {
        fast = fast -> next;
    }
    while (fast -> next) {
        fast = fast -> next;
        slow = slow -> next;
    }

    fast -> next = head;
    ListNode* newhead = slow -> next;
    slow -> next = nullptr;
    return newhead;
}

// https://leetcode-cn.com/problems/rotate-list/solution/xuan-zhuan-lian-biao-by-leetcode-solutio-woq1/
// 

ListNode* rotateRight(ListNode* head, int k) {
    if (k == 0 || !head || !head -> next) return head;

    int n = 1;
    ListNode* iter = head;
    while (iter -> next != nullptr) {
        iter = iter -> next;
        ++n;
    }
    
    int add = n - k % n;
    if (add == n) return head;
    iter -> next = head;    // 连接最后与头结点，成环
    while (add--) {
        iter = iter -> next;
    }
    ListNode* ret = iter -> next;
    iter -> next = nullptr;
    return ret;
}

// 闭合成环
ListNode* rotateRight(ListNode* head, int k) {
    if (k == 0 || !head || !head -> next) return head;
    ListNode* node = head;
    int size = 1;
    while (node -> next) {
        node = node -> next;
        ++size;
    }

    node -> next = head;
    int add = size - k % size;
    while (add--) {
        node = node -> next;
    }
    ListNode* res = node -> next;
    node -> next = nullptr;
    return res;
}