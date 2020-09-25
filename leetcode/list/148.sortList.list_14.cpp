#include <iostream>
#include "listNode.h"
using namespace std;


// �ݹ�ⷨ
ListNode* sortList(ListNode* head) {
    // base case
    if (!head || !head -> next) return head;

    // �ҵ��м���
    ListNode* fast = head -> next;
    ListNode* slow = head;
    while (fast && fast -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    // ����
    ListNode* second = slow -> next;
    slow -> next = NULL;

    // �ݹ�ֿ�����
    ListNode* left = sortList(head);
    ListNode* right = sortList(second);

    // �ϲ�
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (left && right) {
        if (left -> val < right -> val) {
            cur -> next = left;
            left = left -> next;
        } else {
            cur -> next = right;
            right = right -> next;
        }
        cur = cur -> next;
    }

    if (left) cur -> next = left;
    if (right) cur -> next = right;

    return dummy -> next;
}

// ����  �ռ�O(1)
ListNode* sortList(ListNode* head) {
    
}