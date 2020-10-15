#include <iostream>
#include <vector>
#include "tree/treeNode.h"
using namespace std;

// review
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}

TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return NULL;
    int rootval = postorder[postEnd];
    int index = 0;
    for (int i = 0; i <= inEnd; i++) {
        if (inorder[i] == rootval){
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