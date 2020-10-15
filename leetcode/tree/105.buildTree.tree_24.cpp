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

    // root�ڵ��Ӧ��ֵ����ǰ���������ĵ�һ��Ԫ��
    int rootval = preorder[preStart];
    // rootval����������е�����
    int index = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootval) {
            index = i;
            break;
        }
    }

    TreeNode* root = new TreeNode(rootval);
    // �ݹ鹹����������

    // preoderλ��
    int leftsize = index - inStart; // ����������
    root -> left = build(preorder, preStart + 1, preStart + leftsize, inorder, inStart, index - 1);
    root -> right = build(preorder, preStart + leftsize + 1, preEnd, inorder, index + 1, inEnd);
    return root;
}