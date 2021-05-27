#include <iostream>
#include <unordered_map>
#include <vector>
#include "treeNode.h"
using namespace std;

// 递归
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, p, q);
    return ans;
}

TreeNode* ans;
bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return false;
    bool lson = dfs(root -> left, p, q);
    bool rson = dfs(root -> right, p, q);
    if ((lson && rson) || ((root -> val == p -> val || root -> val == q -> val) && (lson || rson))) {
        ans = root;
    }
    return lson || rson || root -> val == p -> val || root -> val == q -> val; 
}

// 存储父节点
unordered_map<int, TreeNode*> father;
unordered_map<int, bool> visited;
void dfs(TreeNode* root) {
    if (root -> left != NULL) {
        father[root -> left -> val] = root;
        dfs(root -> left);
    }
    if (root -> right != NULL) {
        father[root -> right -> val] = root;
        dfs(root -> right);
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    father[root -> val] = NULL;
    dfs(root);
    while (p != NULL) {
        visited[p -> val] = true;
        p = father[p -> val];
    }
    while (q != NULL) {
        if (visited[q -> val]) return q;
        q = father[q -> val];
    }
    return NULL;
}


// review 2021年5月27日15:24:10
TreeNode* ancestor;
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, p, q);
    return ancestor;
}

bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return false;
    bool lson = dfs(root -> left, p, q);
    bool rson = dfs(root -> right, p, q);
    if (((lson || rson) && (root -> val == p -> val || root -> val == q -> val)) || (lson && rson)) {
        ancestor = root;
    }
    return lson || rson || root -> val == p -> val || root -> val == q -> val;
}


unordered_map<int, TreeNode*> father;
unordered_map<int, bool> visited;

void dfs(TreeNode* root) {
    if (root -> left) {
        father[root -> left -> val] = root;
        dfs(root -> left);
    }

    if (root -> right) {
        father[root -> right -> val] = root;
        dfs(root -> right);
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root);
    while (p) {
        visited[p -> val] = true;
        p = father[p -> val];
    }

    while (q) {
        if (visited[q -> val]) return q;
        q = father[q -> val];
    }
    return nullptr;
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root -> left, p, q);
    TreeNode* right = lowestCommonAncestor(root -> right, p, q);
    if (left == nullptr) return right;
    if (right == nullptr) return left;
    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root -> left, p, q);
    TreeNode* right = lowestCommonAncestor(root -> right, p, q);
    if (left == nullptr && right == nullptr) return nullptr;
    if (left == nullptr) return right;
    if (right == nullptr) return left;
    return root;
}