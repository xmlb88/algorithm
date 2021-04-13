#include <iostream>
#include "treeNode.h"
using namespace std;

// µÝ¹é WA
// int res = INT_MAX;
// int minDiffInBST(TreeNode* root) {
//     if (root -> left) {
//         res = min(res, abs(root -> val - root -> left -> val));
//         minDiffInBST(root -> left);
//     }

//     if (root -> right) {
//         res = min(res, abs(root -> val - root -> right -> val));
//         minDiffInBST(root -> right);
//     }

//     return res;  
// }

// ÖÐÐò±éÀú
int res = INT_MAX;
TreeNode* pre;

void traversal(TreeNode* cur) {
    if (cur == NULL) return;
    traversal(cur -> left);
    if (pre != NULL) {
        res = min(res, cur -> val - pre -> val);
    }
    pre = cur;
    traversal(cur -> right);
}

int minDiffInBST(TreeNode* root) {
    traversal(root);
    return res;
}

// TODO: