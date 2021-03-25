#include <iostream>
#include "listNode.h"
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;
    ListNode* dummy = new ListNode();
    dummy -> next = head;
    ListNode *prev = dummy, *curr = head, *nxt = head -> next;

    while (nxt) {
        if (curr -> val == nxt -> val) {
            while (nxt && curr -> val == nxt -> val) {
                curr = nxt;
                nxt = nxt -> next;
            }

            prev -> next = nxt;
            curr = nxt;
            if (nxt)
                nxt = nxt -> next;
        } else {
            prev = curr;
            curr = nxt;
            nxt = nxt -> next;
        }
    }
    return dummy -> next;
}


// 官方一次遍历
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/solution/shan-chu-pai-xu-lian-biao-zhong-de-zhong-oayn/
// 
ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;

    ListNode* dummy = new ListNode(0, head);
    ListNode* cur = dummy;
    while (cur -> next && cur -> next -> next) {
        if (cur -> next -> val == cur -> next -> next -> val) {
            int x = cur -> next -> val;
            while (cur -> next && cur -> next -> val == x) {
                cur -> next = cur -> next -> next;
            }
        } else {
            cur = cur -> next;
        }
    }
    return dummy -> next;
}

// own again
ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;

    ListNode* dummy = new ListNode(0, head);

    ListNode* curr = dummy;
    while (curr -> next && curr -> next -> next) {
        if (curr -> next -> val == curr -> next -> next -> val) {
            int x = curr -> next -> val;
            while (curr -> next && curr -> next -> val == x) {
                curr -> next = curr -> next -> next;
            }
        } else {
            curr = curr -> next;
        }
    }
    return dummy -> next;

}

// 递归
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/solution/fu-xue-ming-zhu-di-gui-die-dai-yi-pian-t-wy0h/
// 

ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head -> next) return head;

    if (head -> val != head -> next -> val) {
        head -> next = deleteDuplicates(head -> next);
    } else {
        ListNode* move = head -> next;
        while (move && head -> val == move -> val) {
            move = move -> next;
        }
        return deleteDuplicates(move);
    }
    return head;
}

// 一次遍历
ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head -> next) return head;
    ListNode* preHead = new ListNode(0, head);
    ListNode *pre = preHead, *cur = head;
    while (cur) {
        while (cur -> next && cur -> val == cur -> next -> val) {
            cur = cur -> next;
        }

        if (pre -> next == cur) {
            pre = pre -> next;
        } else {
            pre -> next = cur -> next;
        }
        cur = cur -> next;
    }
    return preHead -> next;
}