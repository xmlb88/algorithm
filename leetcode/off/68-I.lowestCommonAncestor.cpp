#include <iostream>
#include <vector>
#include <unordered_map>
#include "tree/treeNode.h"
using namespace std;

TreeNode* ans;
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, p, q);
    return ans;
}

bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return false;

    bool lson = dfs(root -> left, p, q);
    bool rson = dfs(root -> right, p, q);
    bool res = (root -> val == p -> val || root -> val == q -> val) && (lson || rson);
    if ((lson && rson) || res) {
        ans = root;
    }

    return lson || rson || root -> val == p -> val || root -> val == q -> val;
}

// ¶þ²æËÑË÷Ê÷
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root != nullptr) {
        if (root -> val < p -> val && root -> val < q -> val) {
            root = root -> right;
        } else if (root -> val > p -> val && root -> val > q -> val) {
            root = root -> left;
        } else break;
    }
    return root;
}