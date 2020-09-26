#include <iostream>
#include "listNode.h"
using namespace std;


// �ݹ�ⷨ
ListNode* sortList(ListNode* head) {
    // base case
    if (!head || !head -> next) return head;

    // �ҵ��м���
    ListNode* fast = head -> next;
    ListNode* slow = head;
    while (fast && fast -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    // ����
    ListNode* second = slow -> next;
    slow -> next = NULL;

    // �ݹ�ֿ�����
    ListNode* left = sortList(head);
    ListNode* right = sortList(second);

    // �ϲ�
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (left && right) {
        if (left -> val < right -> val) {
            cur -> next = left;
            left = left -> next;
        } else {
            cur -> next = right;
            right = right -> next;
        }
        cur = cur -> next;
    }

    if (left) cur -> next = left;
    if (right) cur -> next = right;

    return dummy -> next;
}

// ����  �ռ�O(1)
ListNode* cut(ListNode* head, int n) {
    ListNode* p = head;
    while (n > 1 && p) {
        n--;
        p = p -> next;
    }

    if (p == NULL) {
        return NULL;
    }

    ListNode* node = p -> next;
    p -> next = NULL;
    return node;
}

ListNode* merge(ListNode* l1, ListNode* l2) {
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
    return dummy -> next;
}

ListNode* sortList(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;
    int length = 0;
    ListNode* p = head;
    // ���������ȣ�Ȼ����ݳ�����cut
    while (p) {
        length++;
        p = p -> next;
    }

    // ��һ��cut1��Ȼ����ݹ鲢��˼·��cut�Ĵ�С����*2��
    // �߽�����size < length, ��Ϊsize == n��ʾ���������ÿ������Ϊn�Ķ��Ѿ��������
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    for (int size = 1; size < length; size *= 2) {
        ListNode* cur = dummy -> next;
        ListNode* tail = dummy;
        while (cur) {
            ListNode* left = cur;
            ListNode* right = cut(left, size);
            cur = cut(right, size);
            tail -> next = merge(left, right);
            while (tail -> next) {
                tail = tail -> next;
            }
        }
    }
    return dummy -> next;
}

ListNode* cut(ListNode* head, int n) {
    ListNode* p = head;
    while (p && n > 1) {
        p = p -> next;
        n--;
    }

    if (p == NULL) return NULL;
    ListNode* node = p -> next;
    p -> next = NULL;
    return node;
}

ListNode* merge(ListNode* l1, ListNode* l2) {
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

    cur -> next = l1 ? l1 : l2;
    return dummy -> next;
}

ListNode* sortList(ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;

    // ���󳤶�
    ListNode* node = head;
    int length = 0;
    while (node) {
        node = node -> next;
        length++;
    }

    // �ֶ�cut��merge
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    for (int size = 1; size < length; size *= 2) {
        ListNode* tail = dummy;
        ListNode* cur = dummy -> next;
        while (cur) {
            ListNode* left = cur;
            ListNode* right = cut(left, size);
            cur = cut(right, size);
            tail -> next = merge(left, right);
            while (tail -> next) {
                tail = tail -> next;
            }
        }
    }

    return dummy -> next;
}