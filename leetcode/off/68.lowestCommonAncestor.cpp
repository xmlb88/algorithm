#include <iostream>
#include <vector>
#include <unordered_map>
#include "tree/treeNode.h"
using namespace std;

// µÝ¹é
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, p, q);
    return ans;
}

TreeNode* ans;
bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return false;

    bool lson = dfs(root -> left, p, q);
    bool rson = dfs(root -> right, p, q);
    bool res = (root -> val == p -> val || root -> val == q -> val) && (lson || rson);
    if ((lson && rson) || res) {
        ans = root;
    }
    return lson || rson || root -> val == p -> val || root -> val == q -> val;
}

// ´æ´¢¸¸½Úµã
unordered_map<int, TreeNode*> fa;
unordered_map<int, bool> vi;
void dfs(TreeNode* root) {
    if (root -> left) {
        fa[root -> left -> val] = root;
        dfs(root -> left);
    }
    if (root -> right) {
        fa[root -> right -> val] = root;
        dfs(root -> right);
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    fa[root -> val] = NULL;
    dfs(root);
    
    while (p) {
        vi[p -> val] = true;
        p = fa[p -> val];
    }

    while (q) {
        if (vi[q -> val]) return q;
        q = fa[q -> val];
    }
    return NULL;
}