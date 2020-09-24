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