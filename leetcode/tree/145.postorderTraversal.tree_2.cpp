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

// 普通迭代
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    TreeNode* cur = root, *prev = nullptr;
    stack<TreeNode*> st;
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

// Morris遍历

void addPath(vector<int>& vec, TreeNode* node) {
    int count = 0;
    while (node != nullptr) {
        ++count;
        vec.emplace_back(node -> val);
        node = node -> right;
    }
    reverse(vec.end() - count, vec.end());
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    TreeNode* cur = root;
    TreeNode* curLeft = nullptr;
    while (cur) {
        curLeft = cur -> left;
        if (curLeft) {
            while (curLeft -> right != nullptr && curLeft -> right != cur)
                curLeft = curLeft -> right;

            if (curLeft -> right == nullptr) {
                curLeft -> right = cur;
                cur = cur -> left;
                continue;
            } else {
                // 当左子树的最右侧节点有指向根结点，
                // 此时说明我们已经进入到了返回上层的阶段，断开连接同时对之前的一层进行翻转并输出
                curLeft -> right = nullptr;
                addPath(res, cur -> left);
            }
        }
        cur = cur -> right;
    }
    // 最后一轮循环结束时，从root结点引申的右结点单链表并没有输出，这里补上
    addPath(res, root);
    return res;
}

// Morris
void addPath(vector<int>& res, TreeNode* root) {
    int count = 0;
    TreeNode* cur = root;
    while (cur) {
        ++count;
        res.push_back(cur -> val);
        cur = cur -> right;
    }
    reverse(res.end() - count, res.end());
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    TreeNode* cur = root;
    TreeNode* curLeft = nullptr;
    while (cur) {
        curLeft = cur -> left;
        if (curLeft) {
            while (curLeft -> right && curLeft -> right != cur)
                curLeft = curLeft -> right;

            if (curLeft -> right == nullptr) {
                curLeft -> right = cur;
                cur = cur -> left;
                continue;
            } else {
                curLeft -> right = nullptr;
                addPath(res, cur -> left);
            }
        }
        cur = cur -> right;
    }
    addPath(res, root);
    return res;
}