#include <iostream>
#include "list/listNode.h"
using namespace std;

// 先找到中点，翻转后半部分，再进行比较
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


// 递归找到尾结点，再与头结点比较
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