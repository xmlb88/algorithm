#include <iostream>
#include <vector>
#include <queue>
#include "listNode.h"
using namespace std;

ListNode* partition(ListNode* head, int x) {
    if (head == NULL) return NULL;
    if (head -> next == NULL) return head;
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    ListNode* last = head;
    while (last -> next != NULL) {
        last = last -> next;
    }
    
    ListNode* la = last;
    ListNode* cur = dummy;
    while (cur != last) {
        if (cur -> next -> val < x) {
            cur = cur -> next;
        } else {
            ListNode *nxt = cur -> next;
            cur -> next = cur -> next -> next;
            la -> next = nxt;
            nxt -> next = NULL;
            la = nxt;
        }
    }

    return dummy -> next;
}

ListNode* partition(ListNode* head, int x) {
    vector<int> min;
    vector<int> max;
    ListNode* pre = head;
    ListNode* cur = head;
    while (pre != NULL) {
        if (pre -> val < x) min.push_back(pre -> val);
        else if (pre -> val >= x) max.push_back(pre -> val);
        pre = pre -> next;
    }

    for (int i = 0; i < min.size(); i++) {
        cur -> val = min[i];
        cur = cur -> next;
    }

    for (int i = 0; i < max.size(); i++) {
        cur -> val = max[i];
        cur = cur -> next;
    }

    return head;
}

// Ë«Ö¸Õë
ListNode* partition(ListNode* head, int x) {
    // ListNode* dummy = new ListNode(0);
    // dummy -> next = head;
    ListNode* before = new ListNode(0);
    ListNode* after = new ListNode(0);
    ListNode* cur_before = before;
    ListNode* cur_after = after;

    while (head != NULL) {
        if (head -> val < x) {
            cur_before -> next = head;
            cur_before = cur_before -> next;
        } else {
            cur_after -> next = head;
            cur_after = cur_after -> next;
        }
        head = head -> next;
    }

    cur_after -> next = NULL;
    cur_before -> next = after -> next;
    return before -> next;
}