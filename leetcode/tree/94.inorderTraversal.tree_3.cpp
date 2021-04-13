#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> result;
vector<int> inorderTraversal(TreeNode* root) {
    if (root == NULL) return result;
    inorderTraversal(root -> left);
    result.push_back(root -> val);
    inorderTraversal(root -> right);
    return result;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop();
            if (node -> right) st.push(node -> right);
            st.push(node);
            st.push(NULL);
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

// review 2021年4月13日18:12:05
vector<int> res;
vector<int> inorderTraversal(TreeNode* root) {
    if (!root) return res;
    inorderTraversal(root -> left);
    res.push_back(root -> val);
    inorderTraversal(root -> right);
    return res;
}

// 迭代
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    while (root != nullptr || !stk.empty()) {
        while (root != nullptr) {
            stk.push(root);
            root = root -> left;
        }

        
    }
}