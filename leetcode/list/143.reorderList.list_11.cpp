#include <iostream>
#include "listNode.h"
#include <vector>
using namespace std;

int count = 1;
vector<ListNode*> vec;
void reorderList(ListNode* head) {
    ListNode* cur = head;
    while (cur) {
        cur = cur -> next;
        count++;
    }
    help(head, 1);
    
    cur = head;
    for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size() - 1) {
            if (cur -> next == vec[i]) cur -> next -> next = NULL;
            else {
                vec[i] -> next = cur -> next;
                cur -> next = vec[i];
                cur = cur -> next -> next;
                cur -> next = NULL;
            }
        } else {
            vec[i] -> next = cur -> next;
            cur -> next = vec[i];
            cur = cur -> next -> next;
        }
    }

    return;

}

void help(ListNode* head, int k) {
    if (head == NULL) return;

    help(head -> next, k + 1);
    if (k > count / 2) {
        vec.push_back(head);
    }
}

// �ռ�O��1��

void reorderList(ListNode* head) {
    if (!head || !head -> next) return;
    ListNode* p = head;
    ListNode* q = head;

    // �ҵ��м���
    while (p != NULL && p -> next != NULL) {
        p = p -> next -> next;
        q = q -> next;
    }
    // q���м��㣬p��β���

    // node �Ǻ�һ�ο�ʼ���
    ListNode* node = q -> next;
    // 2������ֿ�
    q -> next = NULL;

    // ��ת��һ�ν��
    ListNode* pre = NULL;
    ListNode* cur = node;
    while (cur) {
        ListNode* node2 = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node2;
    }

    // ���ͷ�����pre����ǰһ��������
    ListNode* ahead = head;
    while (ahead && pre) {
        ListNode* nxt1 = ahead -> next;
        ListNode* nxt2 = pre -> next;
        pre -> next = ahead -> next;
        ahead -> next = pre;
        ahead = nxt1;
        pre = nxt2;
    }

    return;

}