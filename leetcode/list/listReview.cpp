#include <iostream>
#include <vector>
#include "listNode.h"
using namespace std;

// 206.反转链表
// 迭代
ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* cur = head;
    while (cur != NULL) {
        ListNode* node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }
    return pre;
}

// 递归
ListNode* reverseList(ListNode* head) {
    if (!head || !head -> next) return head;
    ListNode* last = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return last;
}


// 92.反转链表II

// 1 -> 2 -> 3 -> 4 -> 5 -> NULL, m = 2, n = 4;
// 1 -> 4 -> 3 -> 2 -> 5 -> NULL
// 迭代
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (n == 1 || !head) return head;
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    ListNode* cur = dummy;
    ListNode *pre = dummy, *start, *end, *nxt;
    int i = 0;
    while (cur != NULL) {
        cur = cur -> next;
        i++;
        if (i == m - 1) pre = cur;
        if (i == m) start = cur;
        if (i == n) end = cur;
    }
    nxt = end -> next;

    cur = start;
    ListNode* prev = NULL;
    while (cur != nxt) {
        ListNode* node = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = node;
    }

    pre -> next = prev;
    start -> next = cur;
    return dummy -> next;
}

// 递归
// 1. 递归反转整个链表
ListNode* reverseList(ListNode* head) {
    if (!head || !head -> next) return head;
    ListNode* last = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return last;
}
// 2. 反转链表前N个节点（递归）
ListNode* successor = NULL;
ListNode* reverseN(ListNode* head, int n) {
    if (n == 1) {
        // 记录第n + 1个节点
        successor = head -> next;
        return head;
    }
    // 以head -> next 为起点，需要反转前n - 1个节点
    ListNode* last = reverseN(head -> next, n - 1);
    
    head -> next -> next = head;
    head -> next = successor;
    return last;
}
// 3. 反转m至n
ListNode* reverseBetween(ListNode* head, int m, int n) {
    // base case
    if (m == 1) {
        return reverseN(head, n);
    }

    // 前进到反转的起点触发base case
    head -> next = reverseBetween(head -> next, m - 1, n - 1);
    return head;
}

// 25. k个一组反转链表
// 迭代
ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) return head;
    ListNode *a = head, *b = head;
    for (int i = 0; i < k; i++) {
        // 不足k个，不需要反转，base case
        if (b == NULL) return head;
        b = b -> next;
    }
    // 反转前k个元素
    ListNode* newHead = reverse(a, b);
    // 递归反转后续链表并连接起来
    a -> next = reverseKGroup(b, k);
    return newHead;
}

ListNode* reverse(ListNode* a, ListNode* b) {
    ListNode* pre = NULL;
    ListNode* cur = a;
    while (cur != b) {
        ListNode* node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }
    return pre;
}

// 234. 回文链表
// 递归后序判断
ListNode* left;
bool isPalindrome(ListNode* head) {
    left = head;
    return traverse(head);
}

bool traverse(ListNode* right) {
    // base case
    if (right == NULL) return true;
    bool res = traverse(right -> next);
    res = res && right -> val == left -> val;
    left = left -> next;
    return res;
}
// 1 -> 2 -> 3 -> 4 -> 5 -> NULL
// 2 -> 3 -> 4 -> 5 -> NULL

// 反转后半部分后进行比较
bool isPalindrome(ListNode* head) {
    // 快慢指针找到中间结点
    // 奇偶情况
    ListNode *fast = head, *slow = head;
    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    ListNode* second = reverse(slow);
    ListNode* first = head;
    while (first != slow) {
        if (first -> val != second -> val) {
            return false;
        } else {
            first = first -> next;
            second = second -> next;
        }
    }
    return true;
}

ListNode* reverse(ListNode* a) {
    ListNode* pre = NULL;
    ListNode* cur = a;
    ListNode* node;
    while (cur != NULL) {
        node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }
    return pre;
}

// 21. 合并2个有序链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (l1 && l2) {
        if (l1 -> val < l2 -> val) {
            cur -> next = l1;
            l1 = l1 -> next;
            cur = cur -> next;
        } else {
            cur -> next = l2;
            l2 = l2 -> next;
            cur = cur -> next;
        }
    }

    if (l1) cur -> next = l1;
    if (l2) cur -> next = l2;

    cur = dummy -> next;
    delete(dummy);
    return cur;
}

// 23. 合并K个升序链表
// 1. 朴素顺序合并
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return NULL;
    ListNode* res = lists[0];
    for (int i = 1; i < lists.size(); i++) {
        res = mergeTwoLists(res, lists[i]);
    }

    return res;
}

// 归并
ListNode* mergeKLists(vector<ListNode*>& lists) {
    return merge(lists, 0, lists.size() - 1);
}

ListNode* merge(vector<ListNode*>& lists, int left, int right) {
    // base case
    if (left == right) return lists[left];
    if (left > right) return NULL;
    int mid = left + (right - left) / 2;
    ListNode* l1 = merge(lists, left, mid);
    ListNode* l2 = merge(lists, mid + 1, right);
    return mergeTwoLists(l1, l2);
}