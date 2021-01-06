#include <iostream>
#include <vector>
#include "tree/treeNode.h"
#include "list/listNode.h"
#include <queue>
using namespace std;

vector<ListNode*> listOfDepth(TreeNode* root) {
    vector<ListNode*> res;
    if (!root) return res;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            cur -> next = new ListNode(node -> val);
            cur = cur -> next;
            if (node -> left) q.push(node -> left);
            if (node -> right) q.push(node -> right);
        }
        ListNode* head = dummy -> next;
        delete(dummy);
        res.push_back(head);
    }
    return res;
}