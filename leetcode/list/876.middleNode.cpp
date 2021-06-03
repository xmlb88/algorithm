#include <iostream>
#include "listNode.h"
using namespace std;

ListNode* middleNode(ListNode* head) {
    if (!head || !head -> next) return head;
    ListNode *slow = head, *fast = head;
    while (fast && fast -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}