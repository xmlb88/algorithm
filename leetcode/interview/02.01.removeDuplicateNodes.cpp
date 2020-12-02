#include <iostream>
#include "list/listNode.h"
#include <unordered_set>
using namespace std;

ListNode* removeDuplicateNodes(ListNode* head) {
    if (!head || !head -> next) return head;
    unordered_set<int> s;
    s.insert(head -> val);
    ListNode* pre = head;
    ListNode* cur = head -> next;

    while (cur) {
        if (s.count(cur -> val)) {
            pre -> next = cur -> next;
            cur = cur -> next;
        } else {
            s.insert(cur -> val);
            pre = pre -> next;
            cur = cur -> next;
        }
    }

    return head;
}