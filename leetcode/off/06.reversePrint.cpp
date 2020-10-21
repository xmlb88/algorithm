#include <iostream>
#include <vector>
#include "list/listNode.h"
#include <stack>
using namespace std;

// 递归
vector<int> res;
vector<int> reversePrint(ListNode* head) {
    print(head);
    return res;
}

void print(ListNode* head) {
    if (head == NULL) return;

    print(head -> next);
    res.push_back(head -> val);
}

// 遍历后反转
vector<int> reversePrint(ListNode* head) {
    vector<int> res;
    while (head) {
        res.push_back(head -> val);
        head = head -> next;
    }
    reverse(res.begin(), res.end());
    return res;
}

// 栈
vector<int> reversePrint(ListNode* head) {
    vector<int> res;
    stack<int> st;
    while (head) {
        st.push(head -> val);
        head = head -> next;
    }
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}