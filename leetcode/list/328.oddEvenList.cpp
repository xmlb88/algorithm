#include <iostream>
#include "listNode.h"
using namespace std;


// own
ListNode* oddEvenList(ListNode* head) {
    if (!head || !head -> next) return head;
    ListNode* odd = new ListNode(0);
    ListNode* even = new ListNode(0);

    ListNode* odd_cur = odd;
    ListNode* even_cur = even;
    ListNode* cur = head;
    int count = 1;
    while (cur) {
        if (count & 1) {
            odd_cur -> next = cur;
            odd_cur = odd_cur -> next;
        } else {
            even_cur -> next = cur;
            even_cur = even_cur -> next;
        }
        cur = cur -> next;
        count++;
    }
    odd_cur -> next = even -> next;
    even_cur -> next = nullptr;
    return odd -> next;
}

// ÓÅ»¯
ListNode* oddEvenList(ListNode* head) {
    if (!head || !head -> next) return head;

    ListNode* evenHead = head -> next;
    ListNode* odd = head;
    ListNode* even = evenHead;

    while (even != nullptr && even -> next != nullptr) {
        odd -> next = even -> next;
        odd = odd -> next;
        even -> next = odd -> next;
        even = even -> next;
    }
    odd -> next = evenHead;
    return head;
}

