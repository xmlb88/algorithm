#include <iostream>
#include <vector>
#include "tree/treeNode.h"
using namespace std;

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return helpBuildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

TreeNode* helpBuildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
    if (preStart > preEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int index;
    for (index = inStart; index <= inEnd; index++) {
        if (inorder[index] == preorder[preStart]) break;
    }

    int leftSize = index - inStart;
    root -> left = helpBuildTree(preorder, preStart + 1, preStart + leftSize, inorder, inStart, index - 1);
    root -> right = helpBuildTree(preorder, preStart + leftSize + 1, preEnd, inorder, index + 1, inEnd);
    return root;
}