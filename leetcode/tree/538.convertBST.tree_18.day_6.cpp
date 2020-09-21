#include <iostream>
#include "treeNode.h"
#include <stack>
using namespace std;

int sum = 0;
TreeNode* convertBST(TreeNode* root) {
    if (root == NULL) return NULL;

    convertBST(root -> right);
    sum += root -> val;
    root -> val = sum;
    convertBST(root -> left);
    return root;
}