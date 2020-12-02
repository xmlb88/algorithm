#include <iostream>
#include "treeNode.h"
using namespace std;

// wa
// int diameterOfBinaryTree(TreeNode* root) {
//     if (root == nullptr) return 0;

//     int left = diameter(root -> left);
//     int right = diameter(root -> right);
//     return max(left + right + 1, max(diameterOfBinaryTree(root -> left), diameterOfBinaryTree(root -> right))) - 1;
// }

// int diameter(TreeNode* root) {
//     if (root == nullptr) return 0;
//     int left = diameter(root -> left);
//     int right = diameter(root -> right);
//     return max(left, right) + 1;
// }

// ¸üÕý
int ans = 0;
int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    depth(root);
    return ans;
}

int depth(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = depth(root -> left);
    int right = depth(root -> right);
    ans = max(ans, left + right + 1);
    return max(left, right) + 1;
}