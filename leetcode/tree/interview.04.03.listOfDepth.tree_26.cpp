#include <iostream>
#include <vector>
#include "treeNode.h"
#include "listNode.h"
#include <queue>
using namespace std;

vector<ListNode*> listOfDepth(TreeNode* tree) {
    vector<ListNode*> result;
    queue<TreeNode*> que;
    if (tree) que.push(tree);
    while (!que.empty()) {
        int size = que.size();
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            cur -> next = new ListNode(node -> val);
            cur = cur -> next;
            if (node -> left) que.push(node -> left);
            if (node -> right) que.push(node -> right);
        }
        result.push_back(dummy -> next);
    }
    return result;
}