#include <iostream>
#include <vector>
#include <queue>
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


// review 2021��5��20��17:25:56
// �����ϲ� �Ż�

ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (l1 && l2) {
        if (l1 -> val < l2 -> val) {
            cur -> next = l1;
            l1 = l1 -> next;
        } else {
            cur -> next = l2;
            l2 = l2 -> next;
        }
        cur = cur -> next;
    }

    cur -> next = l1 ? l1 : l2;
    return dummy -> next;
}

ListNode* mergeHelper(vector<ListNode*>& lists, int left, int right) {
    if (left > right) return nullptr;
    if (left == right) return lists[left];
    int mid = left + (right - left) / 2;
    return mergeTwoList(mergeHelper(lists, left, mid), mergeHelper(lists, mid + 1, right));
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    return mergeHelper(lists, 0, lists.size() - 1);
}

// С����
ListNode* mergeKLists(vector<ListNode*>& lists) {
    // С����
    auto cmp = [] (ListNode* a, ListNode* b) {
        return a -> val > b -> val;
    };

    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
    for (auto node : lists) {
        if (node) q.push(node);
    }

    ListNode head, *cur = &head;
    while (!q.empty()) {
        ListNode* node = q.top();
        q.pop();
        cur -> next = node;
        cur = cur -> next;
        if (node -> next) q.push(node -> next);
    }
    return head.next;
}

// ag
// С����
struct compare{
    bool operator() (ListNode* a, ListNode* b) {
        return a -> val > b -> val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> q;
    for (auto node : lists) {
        if (node) q.push(node);
    }

    ListNode head, *cur = &head;
    while (!q.empty()) {
        ListNode* node = q.top();
        q.pop();
        cur -> next = node;
        cur = cur -> next;
        if (node -> next) q.push(node -> next);
    }
    return head.next;
}