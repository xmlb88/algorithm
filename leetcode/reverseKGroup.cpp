#include<iostream>

// ��ת��aΪͷ��������
ListNode* reverse(ListNode* a) {
    ListNode* pre, cur, nxt;
    pre = NULL, cur = a, nxt = a;
    while(cur != NULL) {
        nxt = cur.next;
        cur.next = pre;
        pre = cur;
        cur = nxt;
    }

    return pre;
}

// ��ת����[a, b)֮���Ԫ�أ� ע������ҿ�
ListNode* reverse(ListNode* a, ListNode* b) {
    ListNode* pre, cur, nxt;
    pre = NULL, cur = a, nxt = a;

    while (cur != b) {
        nxt = cur.next;
        cur.next = pre;
        pre = cur;
        cur = nxt;
    }

    return pre;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) return NULL;
    // ����[a, b)����k������תԪ��
    ListNode* a, b;
    a = b = head;
    for (int i = 0; i < k; i++) {
        if (b == NULL) return head;
        b = b.next;
    }
    
    // ��תǰk��Ԫ��
    ListNode* newHead = reverse(a, b);
    // �ݹ鷴ת����������������
    a.next = reverseKGroup(b, k);

    return newHead;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *a;
    ListNode *b;

    for (int i = 0; i < k; i++) {
        if (b == NULL) return head;
        b = b -> next;
    }

    ListNode *newHead = reverse(a, b);
    a -> next = reverseKGrouop(b, k);

    return newHead;
}

ListNode* reverse(ListNode* a, ListNode* b) {
    ListNode *pre = NULL;
    ListNode *cur = a;
    ListNode *nxt = a;

    while (cur != b) {
        nxt = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = nxt;
    }

    return pre;
}

