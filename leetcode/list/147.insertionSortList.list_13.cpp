#include <iostream>
#include "listNode.h"
using namespace std;

ListNode* insertionSortList(ListNode* head) {
    if (!head || !head -> next) return head;
    ListNode* tail = head;
    ListNode* sort = head -> next;
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;

    while (sort) {
        if (sort -> val < tail -> val) {
            ListNode* pos = dummy;
            while (pos -> next -> val < sort -> val) pos = pos -> next;
            tail -> next = sort -> next;
            sort -> next = pos -> next;
            pos -> next = sort;
            sort = tail -> next;
        } else {
            sort = sort -> next;
            tail = tail -> next;
        }
    }

    return dummy -> next;
}

// review
// 2020年11月20日09:27:05
ListNode* insertionSortList(ListNode* head) {
    if (!head || !head -> next) return head;
    ListNode* cur = head -> next;
    // ListNode* tail = head;
    head -> next = nullptr;

    while (cur) {
        ListNode* pre = nullptr;
        ListNode* back = head;
        ListNode* nextNode = cur -> next;
        while (back && back -> val <= cur -> val) {
            pre = back;
            back = back -> next;
        }

        if (!pre) {
            cur -> next = head;
            head = cur;
        } else {
            pre -> next = cur;
            cur -> next = back;
        }
        cur = nextNode;
    }

    return head;
}

// 更好的解法
ListNode* insertionSortList(ListNode* head) {
    if (!head) return head;
    ListNode* dummyHead = new ListNode(0);
    dummyHead -> next = head;
    ListNode* lastSorted = head;
    ListNode* curr = head -> next;
    while (curr) {
        if (lastSorted -> val <= curr -> val) {
            lastSorted = lastSorted -> next;
        } else {
            ListNode* prev = dummyHead;
            while (prev -> next -> val <= curr -> val) {
                prev = prev -> next;
            }
            lastSorted -> next = curr -> next;
            curr -> next = prev -> next;
            prev -> next = curr;
        }
        curr = lastSorted -> next;
    }
    return dummyHead -> next;
}