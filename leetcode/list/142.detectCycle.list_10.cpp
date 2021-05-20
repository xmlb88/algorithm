#include <iostream>
#include "listNode.h"
using namespace std;

// ����ָ���жϻ�
// ����������ָ����Ϊ��㣬һ���ƶ��ҵ�����ʼ���
ListNode* detectCycle(ListNode* head) {
    if (!head || !head -> next) return NULL;
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
        if (fast == slow) break;
    }

    if (fast != slow) return NULL;

    fast = head;
    while (fast != slow) {
        fast = fast -> next;
        slow = slow -> next;
    }

    return fast;
}


// review day
ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
        if (slow == fast) {
            break;
        }
    }

    if (fast == NULL || fast -> next == NULL) return NULL;

    fast = head;
    while (fast != slow) {
        fast = fast -> next;
        slow = slow -> next;
    }

    return fast;
}


// review 2021��5��20��09:20:14
ListNode* detectCycle(ListNode* head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (fast == slow) break;
    }

    if (!fast || !fast -> next) return nullptr;
    fast = head;
    while (fast != slow) {
        fast = fast -> next;
        slow = slow -> next;
    }
    return fast;
}