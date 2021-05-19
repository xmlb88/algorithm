#include <iostream>
#include <vector>
#include "listNode.h"
using namespace std;

// 3 2 1 0
ListNode* deleteNodes(ListNode* head, int m, int n) {
    ListNode* cur = head;
    while (cur) {
        int i = m;
        while (--i && cur) {
            cur = cur -> next;
        }
        ListNode* prev = cur;
        int j = n + 1;
        while (j-- && cur) {
            cur = cur -> next;
        }
        if (prev) prev -> next = cur;
    }
    return head;
}

ListNode* deleteNodes(ListNode* head, int m, int n) {
    ListNode* cur = head;
    int i = m, j = n + 1;
    while (--i && cur) {
        cur = cur -> next;
    }
    ListNode* prev = cur;
    while (j-- && cur) {
        cur = cur -> next;
    }
    if (prev) prev -> next = deleteNodes(cur, m, n);
    return head;
}