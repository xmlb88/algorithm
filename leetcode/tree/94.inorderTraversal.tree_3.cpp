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


// review 2021年5月25日14:55:44
// 递归
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
}

void inorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    inorder(root -> left, res);
    res.push_back(root -> val);
    inorder(root -> right, res);
}

// 迭代 通用
vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> res;
    if (root) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        if (node) {
            if (node -> right) st.push(node -> right);
            st.push(node);
            st.push(nullptr);
            if (node -> left) st.push(node -> left);
        } else {
            node = st.top();
            st.pop();
            res.push_back(node -> val);
        }
    }
    return res;
}

// 迭代
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur != nullptr || !st.empty()) {
        while (cur) {
            st.push(cur);
            cur = cur -> left;
        }

        cur = st.top();
        st.pop();
        res.push_back(cur -> val);
        cur = cur -> right;
    }
    return res;
}

// 中序遍历 普通迭代
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        while (cur) {
            st.push(cur);
            cur = cur -> left;
        }

        cur = st.top();
        st.pop();
        res.push_back(cur -> val);
        cur = cur -> right;
    }
    return res;
}

// Morris遍历
vector<int> inorderTraversal(TreeNode* root) {
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
            } else curLeft -> right = nullptr;
        }
        // 左子树为空，说明左侧到头，直接输出并返回上层
        res.push_back(cur -> val);
        cur = cur -> right;
    }
    return res;
}


// Morris
vector<int> inorderTraversal(TreeNode* root) {
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
            } else curLeft -> right = nullptr;
        }
        res.push_back(cur -> val);
        cur = cur -> right;
    }
    return res;
}