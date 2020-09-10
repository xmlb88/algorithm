#include<iostream>

// 反转以a为头结点的链表
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

// 反转区间[a, b)之间的元素， 注意左闭右开
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
    // 区间[a, b)包含k个待反转元素
    ListNode* a, b;
    a = b = head;
    for (int i = 0; i < k; i++) {
        if (b == NULL) return head;
        b = b.next;
    }
    
    // 反转前k个元素
    ListNode* newHead = reverse(a, b);
    // 递归反转后续链表并连接起来
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

