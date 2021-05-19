#include <iostream>
#include <vector>
#include "listNode.h"
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return nullptr;
    ListNode* head = new ListNode(0);
    int add = 0;
    if (l1 || l2) {
        int value = add;
        if (l1) {
            value += l1 -> val;
            l1 = l1 -> next;
        }
    }
}