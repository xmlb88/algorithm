#include <iostream>
#include "listNode.h"
#include <vector>
using namespace std;

int count = 1;
vector<ListNode*> vec;
void reorderList(ListNode* head) {
    ListNode* cur = head;
    while (cur) {
        cur = cur -> next;
        count++;
    }
    help(head, 1);
    
    cur = head;
    for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size() - 1) {
            if (cur -> next == vec[i]) cur -> next -> next = NULL;
            else {
                vec[i] -> next = cur -> next;
                cur -> next = vec[i];
                cur = cur -> next -> next;
                cur -> next = NULL;
            }
        } else {
            vec[i] -> next = cur -> next;
            cur -> next = vec[i];
            cur = cur -> next -> next;
        }
    }

    return;

}

void help(ListNode* head, int k) {
    if (head == NULL) return;

    help(head -> next, k + 1);
    if (k > count / 2) {
        vec.push_back(head);
    }
}

// 空间O（1）

void reorderList(ListNode* head) {
    if (!head || !head -> next) return;
    ListNode* p = head;
    ListNode* q = head;

    // 找到中间结点
    while (p != NULL && p -> next != NULL) {
        p = p -> next -> next;
        q = q -> next;
    }
    // q是中间结点，p是尾结点

    // node 是后一段开始结点
    ListNode* node = q -> next;
    // 2段链表分开
    q -> next = NULL;

    // 反转后一段结点
    ListNode* pre = NULL;
    ListNode* cur = node;
    while (cur) {
        ListNode* node2 = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node2;
    }

    // 后段头结点变成pre，与前一段相连接
    ListNode* ahead = head;
    while (ahead && pre) {
        ListNode* nxt1 = ahead -> next;
        ListNode* nxt2 = pre -> next;
        pre -> next = ahead -> next;
        ahead -> next = pre;
        ahead = nxt1;
        pre = nxt2;
    }

    return;

}


// review day_exercise
ListNode* reorderList(ListNode* head) {
    if (!head || !head -> next) return;
    ListNode *fast = head, *slow = head, *slow_pre;
    while (fast && fast -> next) {
        fast = fast -> next -> next;
        slow_pre = slow;
        slow = slow -> next;
    }

    slow_pre -> next = NULL;
    ListNode* cur = slow;
    ListNode* pre = NULL;
    ListNode* node = NULL;
    while (cur) {
        node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }

    ListNode* first = head;
    ListNode* second = pre;
    ListNode* last;
    while (first && second) {
        ListNode* f_nxt = first -> next;
        ListNode* s_nxt = second -> next;
        first -> next = second;
        second -> next = f_nxt;
        last = second;
        first = f_nxt;
        second = s_nxt;
    }

    if (second) {
        last -> next = second;
    }

    return head;
}

// 1. 利用vector
void reorderList(ListNode* head) {
    if (!head || !head -> next) return;
    vector<ListNode*> vec;
    ListNode* cur = head;
    while (cur) {
        vec.push_back(cur);
        cur = cur -> next;
    }
    
    int i = 0, j = vec.size() - 1;
    ListNode* last;
    while (i < j) {
        vec[i] -> next = vec[j];
        vec[j] -> next = vec[i + 1];
        last = vec[i + 1];
        i++;
        j--;
    }

    last -> next = NULL;
    return;
}


// 2. 递归
void reorderList(ListNode* head) {
    if (!head || !head -> next) return;
    // 节点个数
    ListNode* p = head;
    int count = 0;
    while (p) {
        count++;
        p = p -> next;
    }
    helper(head, count);
}

ListNode* helper(ListNode* head, int len) {
    if (len == 1) {
        ListNode* outTail = head -> next;
        head -> next = NULL;
        return outTail;
    }

    if (len == 2) {
        ListNode* outTail = head -> next -> next;
        head -> next -> next = NULL;
        return outTail;
    }

    ListNode* tail = helper(head -> next, len - 2);
    ListNode* subHead = head -> next;
    head -> next = tail;
    ListNode* outTail = tail -> next;
    tail -> next = subHead;
    return outTail;
}

// 3. 求中间节点 + 反转后半段 + 连接
void reorderList(ListNode* head) {
    if (!head || !head -> next || !head -> next -> next) return;
    ListNode *fast = head, *slow = head;
    while (fast -> next && fast -> next -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    ListNode* mid = slow -> next;
    slow -> next = NULL;

    ListNode *l1 = head, *l2 = reverse(mid);
    mergeList(l1, l2);

}

ListNode* reverse(ListNode* p) {
    ListNode* pre = NULL;
    ListNode* cur = p;
    while (cur) {
        ListNode* node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }
    return pre;
}

void mergeList(ListNode* l1, ListNode* l2) {
    ListNode* l1_tmp;
    ListNode* l2_tmp;
    while (l1 && l2) {
        l1_tmp = l1 -> next;
        l2_tmp = l2 -> next;
        l1 -> next = l2;
        l2 -> next = l1_tmp;
        l1 = l1_tmp;
        l2 = l2_tmp;
    }
}