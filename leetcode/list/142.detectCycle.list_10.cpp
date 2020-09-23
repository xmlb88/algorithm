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