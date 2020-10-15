#include <iostream>
#include "treeNode.h"
using namespace std;

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}

TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
    // base case
    if (inStart > inEnd || postStart > postEnd) return NULL;

    int rootval = postorder[postEnd];
    int index = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootval) {
            index = i;
            break;
        }
    }

    TreeNode* root = new TreeNode(rootval);
    int leftsize = index - inStart;
    root -> left = build(inorder, inStart, index - 1, postorder, postStart, postStart + leftsize - 1);
    root -> right = build(inorder, index + 1, inEnd, postorder, postStart + leftsize, postEnd - 1);
    return root;
}