#include <iostream>
#include <string>
#include "treeNode.h"
#include <queue>
#include <stack>
using namespace std;

// µÝ¹é
string tree2str(TreeNode* root) {
    if (!root) return "";
    string s;
    s += to_string(root -> val);
    if (root -> left && root -> right) {
        s += "(" + tree2str(root -> left) + ")(" + tree2str(root -> right) + ")";
    } else if (root -> left) {
        s += "(" + tree2str(root -> left) + ")";
    } else if (root -> right) {
        s += "()(" + tree2str(root -> right) + ")";
    }
    return s;
}

string tree2str(TreeNode* root) {
    if (!root) return "";
    string s;
    s += to_string(root -> val);
    if (!root -> left && !root -> right) {
        return s;
    } else if (!root -> right) {
        s += "(" + tree2str(root -> left) + ")";
    } else {
        s += "(" + tree2str(root -> left) + ")(" + tree2str(root -> right) + ")";
    }
    return s;
}

// µü´ú
// TODO: