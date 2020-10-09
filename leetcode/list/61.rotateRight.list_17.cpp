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