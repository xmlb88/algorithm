#include <iostream>
#include <vector>
#include "listNode.h"
using namespace std;

// 206.��ת����
// ����
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

// �ݹ�
ListNode* reverseList(ListNode* head) {
    if (!head || !head -> next) return head;
    ListNode* last = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return last;
}


// 92.��ת����II

// 1 -> 2 -> 3 -> 4 -> 5 -> NULL, m = 2, n = 4;
// 1 -> 4 -> 3 -> 2 -> 5 -> NULL
// ����
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

// �ݹ�
// 1. �ݹ鷴ת��������
ListNode* reverseList(ListNode* head) {
    if (!head || !head -> next) return head;
    ListNode* last = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return last;
}
// 2. ��ת����ǰN���ڵ㣨�ݹ飩
ListNode* successor = NULL;
ListNode* reverseN(ListNode* head, int n) {
    if (n == 1) {
        // ��¼��n + 1���ڵ�
        successor = head -> next;
        return head;
    }
    // ��head -> next Ϊ��㣬��Ҫ��תǰn - 1���ڵ�
    ListNode* last = reverseN(head -> next, n - 1);
    
    head -> next -> next = head;
    head -> next = successor;
    return last;
}
// 3. ��תm��n
ListNode* reverseBetween(ListNode* head, int m, int n) {
    // base case
    if (m == 1) {
        return reverseN(head, n);
    }

    // ǰ������ת����㴥��base case
    head -> next = reverseBetween(head -> next, m - 1, n - 1);
    return head;
}

// 25. k��һ�鷴ת����
// ����
ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) return head;
    ListNode *a = head, *b = head;
    for (int i = 0; i < k; i++) {
        // ����k��������Ҫ��ת��base case
        if (b == NULL) return head;
        b = b -> next;
    }
    // ��תǰk��Ԫ��
    ListNode* newHead = reverse(a, b);
    // �ݹ鷴ת����������������
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

// 234. ��������
// �ݹ�����ж�
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

// ��ת��벿�ֺ���бȽ�
bool isPalindrome(ListNode* head) {
    // ����ָ���ҵ��м���
    // ��ż���
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

// 21. �ϲ�2����������
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

// 23. �ϲ�K����������
// 1. ����˳��ϲ�
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return NULL;
    ListNode* res = lists[0];
    for (int i = 1; i < lists.size(); i++) {
        res = mergeTwoLists(res, lists[i]);
    }

    return res;
}

// �鲢
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