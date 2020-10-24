#include <iostream>
#include <unordered_map>
#include <vector>
#include "treeNode.h"
using namespace std;

// µÝ¹é
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // TODO #4:
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

// ´æ´¢¸¸½Úµã
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