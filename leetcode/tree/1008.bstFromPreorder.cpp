#include <iostream>
#include <vector>
#include <algorithm>
#include "treeNode.h"
using namespace std;

// 前序遍历 中左右  中序遍历 左中右
TreeNode* bstFromPreorder(vector<int>& preorder) {
    vector<int> inorder(preorder);
    sort(inorder.begin(), inorder.end());
    return makeBST(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

// [1, 2, 3, 4, 5] [2, 3, 1, 4, 5]
TreeNode* makeBST(vector<int>& preorder, vector<int>& inorder, int pre_i, int pre_j, int in_i, int in_j) {
    if (pre_i > pre_j) return nullptr;
    TreeNode* root = new TreeNode(preorder[pre_i]);
    if (pre_i == pre_j) return root;

    int index;
    for (int i = in_i; i <= in_j; ++i) {
        if (inorder[i] == preorder[pre_i]) {
            index = i;
            break;
        }
    }
    int len = index - in_i;
    root -> left = makeBST(preorder, inorder, pre_i + 1, pre_i + len, in_i, index - 1);
    root -> right = makeBST(preorder, inorder, pre_i + len + 1, pre_j, index + 1, in_j);
    return root;
}


// TODO:
// https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal/solution/jian-kong-er-cha-shu-by-leetcode/
// 

// [8, 5, 1, 7, 10, 12]
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int id = 0;
    return dfs(preorder, id, INT_MIN, INT_MAX);
}

TreeNode* dfs(vector<int>& pre, int& id, int lowerBound, int upperbound) {
    if (id == pre.size()) return nullptr;

    int cur = pre[id];
    if (cur < lowerBound || cur > upperbound) return nullptr;
    TreeNode* root = new TreeNode(cur);
    ++id;
    root -> left = dfs(pre, id, lowerBound, cur);
    root -> right = dfs(pre, id, cur, upperbound);
    return root;
}