#include <iostream>
#include "treeNode.h"
#include <stack>
using namespace std;

int res = INT_MAX;
int getMinimumDifference(TreeNode* root) {
    int pre = -1;
    dfs(root, pre);
    return res;
}

void dfs(TreeNode* root, int& pre) {
    if (root == NULL) return;
    dfs(root -> left, pre);
    if (pre == -1) {
        pre = root -> val;
    } else {
        res = min(res, root -> val - pre);
        pre = root -> val;
    }
    dfs(root -> right, pre);
}

// µü´ú
int getMinimumDifference(TreeNode* root) {
    stack<TreeNode*> st;
    st.push(root);
    int res = INT_MAX;
    int pre = -1;
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        if (node != NULL) {
            if (node -> right) st.push(node -> right);
            st.push(node);
            st.push(NULL);
            if (node -> left) st.push(node -> left);
        } else {
            node = st.top();
            st.pop();
            if (pre == -1) {
                pre = node -> val;
            } else {
                res = min(res, node -> val - pre);
                pre = node -> val;
            }
        }
    }

    return res;
}