#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "treeNode.h"
using namespace std;

int sum = 0;
int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return sum;
    if (root -> val >= low && root -> val <= high) {
        sum += root -> val;
    }
    rangeSumBST(root -> left, low, high);
    rangeSumBST(root -> right, low, high);
    return sum;
}

int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;

    if (root -> val > high) {
        return rangeSumBST(root -> left, low, high);
    }

    if (root -> val < low) {
        return rangeSumBST(root -> right, low, high);
    }

    return root -> val + rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
}


int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    if (!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node == nullptr) continue;

        if (node -> val > high) {
            q.push(node -> left);
        } else if (node -> val < low) {
            q.push(node -> right);
        } else {
            sum += node -> val;
            q.push(node -> left);
            q.push(node -> right);
        }
    }
    return sum;
}