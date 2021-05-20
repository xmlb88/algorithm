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

// review
ListNode* reverseList(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;
    ListNode* last = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return last;
}



// review 2021年3月18日11:02:18
ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* prev = new ListNode(0);
    prev -> next = head;
    ListNode* curr = head;
    ListNode* dummy = prev;

    for (int i = 1; i < m; i++) {
        prev = curr;
        curr = curr -> next;
    }

    for (int i = m; i < n; i++) {
        ListNode* node = curr -> next;
        curr -> next = node -> next;
        node -> next = prev -> next;
        prev -> next = node;
    }
    return dummy -> next;
    
}

// 1 -> 2 -> 3 -> 4 -> 5 m = 2, n = 4
// dummy -> 1 -> 2 -> 3 -> 4 -> 5   prev = dummy, curr = 1
// dummy -> 1 -> 2 -> 3 -> 4 -> 5   prev = 1, curr = 2
// dummy -> 1 -> 2 -> 3 -> 4 -> 5   prev = 1, curr = 2
// node = 3 curr -> next : 2 -> next = 4
// node -> next : 3 -> next = 2 prev -> next = 1 -> next = 3
// dummy -> 1 -> 3 -> 2 -> 4



// review 2021年5月20日10:14:05
// 普通解法，切断，反转，再连接

ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr, *cur = head;
    while (cur) {
        ListNode* node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }
    return pre;
}

// 1 2 3 4 5
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;

    ListNode* pre = dummy;
    for (int i = 0; i < left - 1; ++i) {
        pre = pre -> next;
    }

    ListNode* start = pre -> next, *end = start;
    for (int i = 0; i < right - left; ++i) {
        end = end -> next;
    }

    ListNode* after = end -> next;

    // 切断
    pre -> next = nullptr;
    end -> next = nullptr;

    reverseList(start);
    pre -> next = end;
    start -> next = after;

    return dummy -> next;
}

// 迭代，穿针引线，一次遍历
// 0 1 2 3 4 5
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    ListNode* pre = dummy;

    for (int i = 0; i < left - 1; ++i) {
        pre = pre -> next;
    }

    ListNode* cur = pre -> next;
    ListNode* nxt;
    for (int i = 0; i < right - left; ++i) {
        nxt = cur -> next;
        cur -> next = nxt -> next;
        nxt -> next = pre -> next;
        pre -> next = nxt;
    }

    return dummy -> next;
}

// ag
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    ListNode* pre = dummy;

    for (int i = 0; i < left - 1; ++i) {
        pre = pre -> next;
    }

    ListNode* cur = pre -> next;
    ListNode* nxt;
    for (int i = 0; i < right - left; ++i) {
        nxt = cur -> next;
        cur -> next = nxt -> next;
        nxt -> next = pre -> next;
        pre -> next = nxt;
    }
    return dummy -> next;
}