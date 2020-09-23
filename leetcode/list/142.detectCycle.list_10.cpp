#include <iostream>
#include "listNode.h"
using namespace std;

// 快慢指针判断环
// 相遇后将任意指针置为起点，一起移动找到环起始结点
ListNode* detectCycle(ListNode* head) {
    if (!head || !head -> next) return NULL;
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
        if (fast == slow) break;
    }

    if (fast != slow) return NULL;

    fast = head;
    while (fast != slow) {
        fast = fast -> next;
        slow = slow -> next;
    }

    return fast;
}