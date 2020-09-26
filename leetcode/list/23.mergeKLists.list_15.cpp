#include <iostream>
#include <vector>
#include "listNode.h"
using namespace std;

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (l1 && l2) {
        if (l1 -> val < l2 -> val) {
            cur -> next = l1;
            l1 = l1 -> next;
            cur = cur -> next;
        } else {
            cur -> next = l2;
            l2 = l2 -> next;
            cur = cur -> next;
        }
    }

    cur -> next = l1 ? l1 : l2;
    return dummy -> next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    return mergehelp(lists, 0, n - 1);
}

ListNode* mergehelp(vector<ListNode*> lists, int l, int r) {
    if (l == r) return lists[l];
    if (l > r) return NULL;
    int mid = l + (r - l) / 2;
    return merge(mergehelp(lists, l, mid), mergehelp(lists, mid + 1, r));
}