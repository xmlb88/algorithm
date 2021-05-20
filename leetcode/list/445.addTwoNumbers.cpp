#include <iostream>
#include <vector>
#include "listNode.h"
#include <stack>
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return nullptr;
    vector<int> v1;
    while (l1) {
        v1.push_back(l1 -> val);
        l1 = l1 -> next;
    }

    vector<int> v2;
    while (l2) {
        v2.push_back(l2 -> val);
        l2 = l2 -> next;
    }

    vector<int> res;
    int add = 0;
    for (int i = v1.size() - 1, j = v2.size() - 1; i >= 0 || j >= 0; --i, --j) {
        if (i >= 0) add += v1[i];
        if (j >= 0) add += v2[j];
        res.push_back(add % 10);
        add /= 10;
    }

    if (add) res.push_back(add);
    ListNode *head = new ListNode(0), *cur = head;
    for (int i = res.size() - 1; i >= 0; --i) {
        cur -> next = new ListNode(res[i]);
        cur = cur -> next;
    }
    return head -> next;
}

// ջ
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    while (l1) {
        s1.push(l1 -> val);
        l1 = l1 -> next;
    }

    while (l2) {
        s2.push(l2 -> val);
        l2 = l2 -> next;
    }

    int carry = 0;
    ListNode* ans = nullptr;
    while (!s1.empty() || !s2.empty() || carry != 0) {
        int value = carry;
        if (!s1.empty()) {
            value += s1.top();
            s1.pop();
        }

        if (!s2.empty()) {
            value += s2.top();
            s2.pop();
        }

        ListNode* cur = new ListNode(value % 10);
        carry = value / 10;
        cur -> next = ans;
        ans = cur;
    }
    return ans;
}