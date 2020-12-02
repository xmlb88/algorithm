#include <iostream>
#include "tree/treeNode.h"
using namespace std;

bool checkSubTree(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return isSame(t1, t2) || checkSubTree(t1 -> left, t2) || checkSubTree(t1 -> right, t2);
}

bool isSame(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    if (t1 -> val != t2 -> val) return false;
    return isSame(t1 -> left, t2 -> left) && isSame(t1 -> right, t2 -> right);
}

// int depth(TreeNode* root) {
//     int level = 0;
//     while (!root) {
//         level++;
//         root = root -> left;
//     } 
//     return level;
// }