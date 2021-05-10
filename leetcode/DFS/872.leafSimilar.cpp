#include <iostream>
#include "tree/treeNode.h"
using namespace std;

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaf1;
    leaf(root1, leaf1);
    vector<int> leaf2;
    leaf(root2, leaf2);
    return leaf1 == leaf2;
}

void leaf(TreeNode* root, vector<int>& l) {
    if (root == nullptr) return;

    if (!root -> left && !root -> right) {
        l.push_back(root -> val);
    }
    leaf(root -> left, l);
    leaf(root -> right, l);
}


// review 2021Äê5ÔÂ10ÈÕ09:59:39
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaf1;
    leaf(root1, leaf1);
    vector<int> leaf2;
    leaf(root2, leaf2);
    return leaf1 == leaf2;
}

void leaf(TreeNode* root, vector<int>& l) {
    if (root == nullptr) return;

    if (!root -> left && !root -> right) {
        l.push_back(root -> val);
    }
    
    leaf(root -> left, l);
    leaf(root -> right, l);
}