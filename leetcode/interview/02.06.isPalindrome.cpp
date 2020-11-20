#include <iostream>
#include "list/listNode.h"
using namespace std;

// ���ҵ��е㣬��ת��벿�֣��ٽ��бȽ�
bool isPalindrome(ListNode* head) {
    if (!head || !head -> next) return true;

    ListNode* fast = head;
    ListNode* slow = head;

    while (fast -> next && fast -> next -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    ListNode* midNode = slow -> next;
    slow -> next = nullptr;

    ListNode* pre = nullptr;
    while (midNode) {
        ListNode* temp = midNode -> next;
        midNode -> next = pre;
        pre = midNode;
        midNode = temp;
    }

    while (head && pre) {
        if (head -> val != pre -> val) return false;
        else {
            head = head -> next;
            pre = pre -> next;
        }
    }

    return true;
}


// �ݹ��ҵ�β��㣬����ͷ���Ƚ�
ListNode* prev;
bool isPalindrome(ListNode* head) {
    prev = head;
    return dfs(head);
}

bool dfs(ListNode* head) {
    if (head == nullptr) return true;

    bool flag = dfs(head -> next);
    flag = flag && (head -> val == prev -> val);
    prev = prev -> next;
    return flag;
}

// 1 2 2 1
// 1 2 5 2 1