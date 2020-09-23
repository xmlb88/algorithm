#include <iostream>
#include "listNode.h"
using namespace std;

// think
// ��ת��aΪͷ��������
ListNode* reverse(ListNode* a) {
    ListNode* pre = NULL;
    ListNode* cur = a;
    while (cur != NULL) {
        ListNode* node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }

    return pre;
}

// ��ת����[a, b)֮���Ԫ�أ�����ҿ�(aΪͷ���)
ListNode* reverseAB(ListNode* a, ListNode* b) {
    ListNode* pre = NULL;
    ListNode* cur = a;
    while (cur != b) {
        ListNode* nxt = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = nxt;
    }

    // ���ط�ת���ͷ���
    return pre;
}


// now?
ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) return NULL;

    // ����[a, b)����k������תԪ��
    ListNode* a = head;
    ListNode* b = head;
    for (int i = 0; i < k; i++) {
        // base case;
        if (b == null) return head;
        b = b -> next;
    }

    // ��תǰk��Ԫ��
    ListNode newHead = reverseAB(a, b);
    // !!�ݹ鷴ת�������� ������Ҫ��������
    a.next = reverseKGroup(b, k);
    return newHead;
}



// review 
ListNode* reverse(ListNode* a, ListNode* b) {
    ListNode* pre = NULL;
    ListNode* cur = a;
    while (cur != b) {
        ListNode* nxt = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = nxt;
    }

    return pre;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* a = head;
    ListNode* b = head;
    for (int i = 0; i < k; i++) {
        if (b == NULL) return head;
        b = b -> next;
    }

    ListNode* newHead = reverse(a, b);
    a -> next = reverseKGroup(b, k);
    return newHead;
}