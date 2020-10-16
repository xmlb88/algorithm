#include <iostream>
#include <vector>
#include "treeNode.h"
using namespace std;

int sumOfTilt;
int findTilt(TreeNode* root) {
    sumOfTilt = 0;
    sumOfNodes(root);
    return sumOfTilt;
}

int sumOfNodes(TreeNode* root) {
    if (root == NULL) return 0;

    int left = sumOfNodes(root -> left);
    int right = sumOfNodes(root -> right);

    sumOfTilt += abs(left - right);
    return left + right + root -> val;
}