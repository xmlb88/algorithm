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

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    preorder(root, result);
    return result;
}

void preorder(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;

    result.push_back(root -> val);
    preorder(root -> left, result);
    preorder(root -> right, result);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop();
            if (node -> right) st.push(node -> right);
            if (node -> left) st.push(node -> left);
            st.push(node);
            st.push(NULL);
        } else {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node -> val);
        }
    }

    return result;
}

// review 2020年10月27日09:09:55

// 递归
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorder(root, res);
    return res;
}

void preorder(TreeNode* root, vector<int>& res) {
    if (root == NULL) return;

    res.push_back(root -> val);
    preorder(root -> left, res);
    preorder(root -> right, res);
}

// 迭代
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop();
            if (node -> right) st.push(node -> right);
            if (node -> left) st.push(node -> left);
            st.push(node);
            st.push(NULL);
        } else {
            st.pop();
            node = st.top();
            st.pop();
            res.push_back(node -> val);
        }
    }
    return res;
}

// 迭代2
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node -> val);
        if (node -> right) st.push(node -> right);
        if (node -> left) st.push(node -> left);
    }
    return res;
}