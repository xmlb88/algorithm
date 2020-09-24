#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return NULL;

    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    ListNode* mid = slow -> next;
    slow -> next = NULL;

    ListNode* pre = NULL;
    ListNode* cur = head;

    while (cur) {
        ListNode node* = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = node;
    }

    return helper(pre, mid);

}

TreeNode* helper(ListNode* le, ListNode* ri) {
    TreeNode* root = new TreeNode(le -> val);
    le = le -> next;

    TreeNode* left = root;
    TreeNode* right = root;

    while (le && ri) {
        TreeNode* node_left = new TreeNode(le -> val);
        TreeNode* node_right = new TreeNode(ri -> val);
        left -> left = node_left;
        right -> right = node_right;
        left = left -> left;
        right = right -> right;
        le = le -> next;
        ri = ri -> next;
    }

    if (ri) {
        right -> right = new TreeNode(ri -> val);
    }

    if (le) {
        left -> left = new TreeNode(le -> val);
    }

    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return NULL;
    if (!head -> next) return new TreeNode(head -> val);

    // 快慢指针找到中点
    ListNode *pre = head, *slow = head -> next, *fast = head -> next -> next;
    while (fast && fast -> next) {
        pre = pre -> next;
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    pre -> next = NULL;
    TreeNode* root = new TreeNode(slow -> val);
    root -> left = sortedListToBST(head);
    root -> right = sortedListToBST(slow -> next);
    return root;
}