#include <iostream>
#include "listNode.h"
using namespace std;

ListNode* tmp = NULL;
ListNode* reverseN(listNode* head, int n) {
    if (n == 1) {
        // 记录n + 1个节点
        tmp = head -> next;
        return head;
    }

    // 以head -> nect为起点，需要反转前n - 1个节点
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

    // 前进到反转的起点触发base case
    head -> next = reverseBetween(head -> next, m - 1, n - 1);
    return head;
}

// 迭代
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


// -------again---------

// 递归
// 先反转整个好吧
ListNode* reverse(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;
    ListNode* last = reverse(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return last;
}

// 反转链表前N个节点
ListNode* successor = NULL;
ListNode* reverseN(ListNode* head, int n) {
    if (n == 1) {
        // 记录第n + 1个节点
        successor = head -> next;
        return head;
    }

    // 以head -> next为起点，反转前n - 1个节点
    ListNode* last = reverseN(head, n - 1);

    head -> next -> next = head;
    head -> next = successor;
    return last;
}

// 反转区间[m, n]，索引从1开始
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m == 1) {
        // base case
        // 相当于反转前n个元素
        return reverseN(head, n);
    }

    //前进到反转的起点触发base case
    head -> next = reverseBetween(head -> next, m - 1, n - 1);
    return head;
}


ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    ListNode* pre = dummy;
    // ListNode* cur = head;
    for (int i = 1; i < m; i++) {
        pre = pre -> next;
        head = head -> next;
    }

    for (int i = m; i < n; i++) {
        // 不对
        // ListNode* node = head -> next;
        // head -> next = pre;
        // pre = head;
        // head = node;
        ListNode* nxt = head -> next;
        head -> next = nxt -> next;
        nxt -> next = pre -> next;
        pre -> next = nxt;
    }

    return dummy -> next;
}