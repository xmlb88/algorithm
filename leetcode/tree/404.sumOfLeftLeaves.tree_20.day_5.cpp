#include<iostream>
#include"treeNode.h"
#include<queue>
#include<stack>
using namespace std;

int result = 0;
int sumOfLeftLeaves(TreeNode* root) {
    if (root == NULL) return 0;
    if (root -> left && !root -> left -> left && !root -> left -> right) result += root -> left -> val;
    sumOfLeftLeaves(root -> left);
    sumOfLeftLeaves(root -> right);

    return result;
}

int sumOfLeftLeaves(TreeNode* root) {
    int result = 0;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        if (node -> left && !node -> left -> left && !node -> left -> right) {
            result += node -> left -> val;
        }
        if (node -> right) st.push(node -> right);
        if (node -> left) st.push(node -> left);
    }
    return result;
}