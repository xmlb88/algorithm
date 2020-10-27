#include <iostream>
#include "list/listNode.h"
using namespace std;

// ???
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    while (headA) {
        ListNode* node = headB;
        while (node) {
            if (headA == node) {
                return headA;
            }
            node = node -> next;
        }
        headA = headA -> next;
    }
    return NULL;
}

// 2�α����������˾�ȥ��һ��
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* node1 = headA;
    ListNode* node2 = headB;
    while (node1 != node2) {
        node1 = node1? node1 -> next : headB;
        node2 = node2? node2 -> next : headA;
    }
    return node1;
}