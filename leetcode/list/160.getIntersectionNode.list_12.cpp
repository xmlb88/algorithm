#include <iostream>
#include "listNode.h"
using namespace std;

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* node1 = headA;
    while (node1) {
        ListNode* node2 = headB;
        while (node2) {
            if (node1 == node2) return node1;
            node2 = node2 -> next;
        }
        node1 = node1 -> next;
    }
    return NULL;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* node1 = headA;
    ListNode* node2 = headB;

    while (node1 != node2) {
        node1 = node1? node1 -> next : headB;
        node2 = node2? node2 -> next : headA;
    }

    return node1;
}

// review 2021年5月19日10:23:51
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode *A = headA, *B = headB;
    while (A != B) {
        if (!A) A = headB;
        else A = A -> next;
        if (!B) B = headA;
        else B = B -> next;
    }
    return A;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode *cur_A = headA, *cur_B = headB;
    while (cur_A != cur_B) {
        cur_A = cur_A ? cur_A -> next : headB;
        cur_B = cur_B ? cur_B -> next : headA;
    }
    return cur_A;
}

// 时间O(n)
// 空间O(1)