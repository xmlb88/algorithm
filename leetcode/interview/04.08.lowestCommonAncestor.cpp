#include <iostream>
#include "tree/treeNode.h"
#include <unordered_map>
using namespace std;

// 记录父节点
unordered_map<TreeNode*, TreeNode*> father;
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    father[root] = nullptr;
    recordFather(root);

    unordered_map<TreeNode*, bool> visited;
    while (p) {
        visited[p] = true;
        p = father[p];
    }

    while (q) {
        if (visited[q] == true) return q;
        q = father[q];
    }

    return root;
}

void recordFather(TreeNode* root) {
    if(root -> left) {
        father[root -> left] = root;
        recordFather(root -> left);
    }

    if (root -> right) {
        father[root -> right] = root;
        recordFather(root -> right);
    }
}

// 递归
TreeNode* ans;
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, p, q);
    return ans;
}

bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return false;

    bool lson = dfs(root -> left, p, q);
    bool rson = dfs(root -> right, p, q);
    if ((lson && rson) || ((lson || rson) && (root -> val == p -> val || root -> val == q -> val))) {
        ans = root;
    }

    return lson || rson || root -> val == p -> val || root -> val == q -> val;
}

// 递归
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;

    // 如果找到了p或q，返回它
    if (root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root -> left, p, q);
    TreeNode* right = lowestCommonAncestor(root -> right, p, q);
    // 如果left和right都记录了找到的节点，那么肯定是一个记录了p，另一个记录了q
    // 它们分别在以root为根的左右子树中，所以root就是它们的最近公共祖先
    if (left != nullptr && right != nullptr) return root;

    return (left != nullptr) ? left : right;
}