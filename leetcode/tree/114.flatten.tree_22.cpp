#include <iostream>
#include "treeNode.h"
using namespace std;

void flatten(TreeNode* root) {
    // base case
    if (root == NULL) return;

    flatten(root -> left);
    flatten(root -> right);

    /*****�������λ��*****/
    // 1.���������Ѿ�����ƽ��һ������
    TreeNode* left = root -> left;
    TreeNode* right = root -> right;

    // 2.����������Ϊ������
    root -> left = NULL;
    root -> right = left;

    // 3.��ԭ�ȵ��������ӵ���ǰ������ĩ��
    TreeNode* p = root;
    while (p -> right != NULL) {
        p = p -> right;
    }
    p -> right = right;
}