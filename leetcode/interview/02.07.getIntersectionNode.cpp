#include <iostream>
#include "list/listNode.h"
using namespace std;

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;

    ListNode* curA = headA;
    ListNode* curB = headB;

    while (true) {
        if (curA == curB) {
            return curA;
        }

        curA = curA -> next;
        curB = curB -> next;

        if (!curA && curB) curA = headB;
        if (!curB && curA) curB = headA;
    }

    return nullptr;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;
    ListNode* curA = headA;
    ListNode* curB = headB;

    while (curA != curB) {
        curA = curA ? curA -> next : headB;
        curB = curB ? curB -> next : headA;
    }

    return curA;
}