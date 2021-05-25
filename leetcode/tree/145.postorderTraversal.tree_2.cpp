#include<iostream>
#include<vector>
#include<stack>
#include "treeNode.h"
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

// review 2021年5月25日18:16:40
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorder(root, res);
    return res;
}

void postorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    postorder(root -> left, res);
    postorder(root -> right, res);
    res.push_back(root -> val);
}

// 迭代 通用
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    if (root) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        if (node) {
            st.push(node);
            st.push(nullptr);
            if (node -> right) st.push(node -> right);
            if (node -> left) st.push(node -> left);
        } else {
            node = st.top();
            st.pop();
            res.push_back(node -> val);
        }
    }
    return res;
}

// 迭代 前序遍历修改 + 反转
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    if (root) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node -> val);
        if (node -> left) st.push(node -> left);
        if (node -> right) st.push(node -> right);
    }
    reverse(res.begin(), res.end());
    return res;
}

// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/er-cha-shu-de-hou-xu-bian-li-by-leetcode-solution/
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode *prev = nullptr, *cur = root;
    while (cur || !st.empty()) {
        while (cur) {
            st.push(cur);
            cur = cur -> left;
        }

        cur = st.top();
        st.pop();
        if (cur -> right == nullptr || cur -> right == prev) {
            res.push_back(cur -> val);
            prev = cur;
            cur = nullptr;
        } else {
            st.push(cur);
            cur = cur -> right;
        }
    }
    return res;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode *cur = root, *prev = nullptr;
    while (cur || !st.empty()) {
        while (cur) {
            st.push(cur);
            cur = cur -> left;
        }

        cur = st.top();
        st.pop();
        if (cur -> right && cur -> right != prev) {
            st.push(cur);
            cur = cur -> right;
        } else {
            res.push_back(cur -> val);
            prev = cur;
            cur = nullptr;
        }
    }
    return res;
}

// 后序遍历 普通迭代
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode *cur = root, prev = nullptr;
    while (cur || !st.empty()) {
        while (cur) {
            st.push(cur);
            cur = cur -> left;
        }

        cur = st.top();
        st.pop();
        if (cur -> right && cur -> right != prev) {
            st.push(cur);
            cur = cur -> right;
        } else {
            res.push_back(cur -> val);
            prev = cur;
            cur = nullptr;
        }
    }
    return res;
}