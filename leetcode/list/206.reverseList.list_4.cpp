#include <iostream>
#include "listNode.h"
using namespace std;

// ����
ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* cur = head;
    while (cur != NULL) {
        ListNode* node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }
    return pre;
}

// �ݹ�
ListNode* reverseList(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;
    ListNode* last = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return last;
}




// review
ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* cur = head;

    while (cur) {
        ListNode* node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }
    return pre;
}

ListNode* reverseList(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;

    ListNode* node = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return node;
}

// review 
ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* cur = head;
    while (cur != NULL) {
        ListNode* node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }

    return pre;
}


// �ݹ�
ListNode* reverseList(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;
    ListNode* last = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return last;
}

ListNode* reverseList(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;
    ListNode* last = reverseList(head -> head);
    head -> next -> next = haed;
    head -> next = NULL;
    return last;
}

ListNode* reverseList(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;
    ListNode* last = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;;
    return last;
}


// review 2021��3��18��11:29:13
ListNode* reverseList(ListNone* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* node = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = node;
    }

    return prev;
}


// review 2021��5��20��10:01:40
// ����
ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr, *cur = head;
    while (cur) {
        ListNode* node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }
    return pre;
}

// �ݹ�
ListNode* reverseList(ListNode* head) {
    if (!head || !head -> next) return head;
    ListNode* nxt = head -> next;
    ListNode* node = reverseList(head -> next);
    nxt -> next = head;
    head -> next = nullptr;
    return node;
}

ListNode* reverseList(ListNode* head) {
    if (!head || !head -> next) return head;
    ListNode* node = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = nullptr;
    return node;
}