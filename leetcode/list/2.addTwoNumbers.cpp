#include <iostream>
#include <vector>
#include "listNode.h"
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return nullptr;
    ListNode* head = new ListNode(0), *cur = head;
    int add = 0;
    while (l1 || l2) {
        int value = add;
        if (l1) {
            value += l1 -> val;
            l1 = l1 -> next;
        }

        if (l2) {
            value += l2 -> val;
            l2 = l2 -> next;
        }

        cur -> next = new ListNode(value % 10);
        cur = cur -> next;
        cout << cur -> val << endl;
        add = value / 10;
    }

    if (add) cur -> next = new ListNode(add);
    return head -> next;
}

int main() {
    vector<int> v1 = {2, 4, 3};
    vector<int> v2 = {5, 6, 4};
    ListNode *head1 = new ListNode(0), *cur1 = head1;
    for (auto v : v1) {
        cur1 -> next = new ListNode(v);
        cur1 = cur1 -> next;
    }

    ListNode *head2 = new ListNode(0), *cur2 = head2;
    for (auto v : v2) {
        cur2 -> next = new ListNode(v);
        cur2 = cur2 -> next;
    }

    ListNode *res = addTwoNumbers(head1 -> next, head2 -> next);
    while (res) {
        cout << res -> val << " ";
        res = res -> next;
    }
}