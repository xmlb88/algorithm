#include <iostream>
#include <vector>
#include "treeNode.h"
using namespace std;

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                vector<int>& inorder, int inStart, int inEnd) {

    // base case
    if (preStart > preEnd) return NULL;

    // root节点对应的值就是前序遍历数组的第一个元素
    int rootval = preorder[preStart];
    // rootval在中序遍历中的索引
    int index = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootval) {
            index = i;
            break;
        }
    }

    TreeNode* root = new TreeNode(rootval);
    // 递归构造左右子树

    // preoder位置
    int leftsize = index - inStart; // 左子树个数
    root -> left = build(preorder, preStart + 1, preStart + leftsize, inorder, inStart, index - 1);
    root -> right = build(preorder, preStart + leftsize + 1, preEnd, inorder, index + 1, inEnd);
    return root;
}