#include <iostream>
#include <vector>
#include <unordered_map>
#include "treeNode.h"
using namespace std;

// own 递归
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p == root || q == root) return root;
    if (p -> val < root -> val && root -> val < q -> val) return root;
    if (q -> val < root -> val && root -> val < p -> val) return root;
    if (p -> val < root -> val && q -> val < root -> val) return lowestCommonAncestor(root -> left, p, q);
    if (p -> val > root -> val && q -> val > root -> val) return lowestCommonAncestor(root -> right, p, q);
    return nullptr;
}

// 2次遍历路径
vector<TreeNode*> getPath(TreeNode* root, TreeNode* target) {
    vector<TreeNode*> path;
    TreeNode* node = root;
    while (node != target) {
        path.push_back(node);
        if (target -> val < node -> val) {
            node = node -> left;
        } else node = node -> right;
    }
    path.push_back(node);
    return path;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> path_p = getPath(root, p);
    vector<TreeNode*> path_q = getPath(root, q);
    TreeNode* ancestor;
    for (int i = 0; i < path_q.size() && i < path_p.size(); ++i) {
        if (path_p[i] == path_q[i]) ancestor = path_p[i];
        else break;
    }
    return ancestor;
}


// 一次遍历，迭代
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* ancestor = root;
    while (true) {
        if (p -> val < ancestor -> val && q -> val < ancestor -> val) {
            ancestor = ancestor -> left;
        } else if (p -> val > ancestor -> val && q -> val > ancestor -> val) {
            ancestor = ancestor -> right;
        } else break;
    }
    return ancestor;
}