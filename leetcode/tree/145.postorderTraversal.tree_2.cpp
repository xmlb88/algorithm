#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> result;
vector<int> postorderTraversal(TreeNode* root) {
    if (root == NULL) return result;

    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    result.push_back(root -> val);

    return result;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop();
            st.push(node);
            st.push(NULL);
            if (node -> right) st.push(node -> right);
            if (node -> left) st.push(node -> left);
        } else {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node -> val);
        }
    }
    return result;
}