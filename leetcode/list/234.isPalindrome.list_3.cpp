#include <iostream>
#include "listNode.h"
using namespace std;

// �ݹ�����ж�
ListNode* left;
bool isPalindrome(ListNode* head) {
    left = head;
    return palind(head);
}

bool palind(ListNode* head) {
    if (head == NULL) return true;

    bool res = palind(head -> next);
    res = res && (head -> val == left -> val);
    left = left -> next;
    return res;
}

// ��ת���κ���жԱ�
bool isPalindrome(ListNode* head) {
    if (head == NULL || head -> next == NULL) return true;

    ListNode* fast = head;
    ListNode* slow = head;
    
    while (fast && fast -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    if (fast != NULL) {
        slow = slow -> next;
    }

    ListNode* pre = NULL;
    ListNode* cur = slow;

    while (cur != NULL) {
        ListNode* node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }

    ListNode* left = head;
    ListNode* right = pre;

    while (right != NULL) {
        if (left -> val != right -> val)
            return false;
        right = right -> next;
        left = left -> next;
    }
    return true;
}

1 2 3 4 5
1 2 3 4 5 6

// review day_exercise
#include <iostream>
#include "listNode.h"
using namespace std;

// 递归判断
ListNode* cur;
bool isPalindrome(ListNode* head) {
    cur = head;
    return palind(head);
}

bool palind(ListNode* head) {
    if (head == NULL) return true;
    bool res = palind(head -> next);
    res = res && (head -> val == cur -> val);
    cur = cur -> next;
    return res;
}
