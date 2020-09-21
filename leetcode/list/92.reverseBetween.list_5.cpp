#include <iostream>
#include "listNode.h"
using namespace std;

ListNode* tmp = NULL;
ListNode* reverseN(listNode* head, int n) {
    if (n == 1) {
        // ��¼n + 1���ڵ�
        tmp = head -> next;
        return head;
    }

    // ��head -> nectΪ��㣬��Ҫ��תǰn - 1���ڵ�
    ListNode* last = reverseN(head -> next, n - 1);

    head -> next -> next = head;
    head -> next = tmp;
    return last;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
    // base case
    if (m == 1) {
        return reverseN(head, n);
    }

    // ǰ������ת����㴥��base case
    head -> next = reverseBetween(head -> next, m - 1, n - 1);
    return head;
}

// ����
ListNode* reverseBetween(ListNode* head, int m, int n) {
    while (m != 1) {
        head = head -> next;
        m--;
        n--;
    }

    ListNode* pre = head;
    ListNode* cur = head;
    while (n != 1) {
        ListNode* node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }

    return head;
}