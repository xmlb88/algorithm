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


// review 2021年5月25日14:33:01
// 递归
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorder(root, res);
    return res;
}

void preorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    res.push_back(root -> val);
    preorder(root -> left, res);
    preorder(root -> right, res);
}

// 迭代 stack
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    if (root) st.push(root);
    vector<int> res;
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node -> val);
        // 右结点先进栈
        if (node -> right) st.push(node -> right);
        if (node -> left) st.push(node -> left);
    }
    return res;
}

// 迭代 通用版
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> res;
    if (root) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        if (node) {
            if (node -> right) st.push(node -> right);
            if (node -> left) st.push(node -> left);
            st.push(node);
            st.push(nullptr);
        } else {
            node = st.top();
            st.pop();
            res.push_back(node -> val);
        }
    }
    return res;
}

// 迭代 指针
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        while (cur) {
            res.push_back(cur -> val);
            st.push(cur -> right);
            cur = cur -> left;
        }
        cur = st.top();
        st.pop();
    }
    return res;
}

// 普通迭代 review
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        while (cur) {
            res.push_back(cur -> val);
            st.push(cur -> right);
            cur = cur -> left;
        }

        cur = st.top();
        st.pop();
    }
    return res;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        while (cur) {
            res.push_back(cur -> val);
            st.push(cur);
            cur = cur -> left;
        }

        cur = st.top();
        st.pop();
        cur = cur -> right;
    }
    return res;
}

// Morris遍历

// 遍历方式
void preorderMorris(TreeNode* root) {
    if (!root) return;
    TreeNode* cur = root;   // 当前节点
    TreeNode* curLeft = nullptr;    // 当前节点的左子树
    while (cur) {
        curLeft = cur -> left;
        // 当前节点的左子树存在即可建立连接
        if (curLeft) {
            // 找到当前左子树的最右侧节点，并且不能沿着连接返回上层
            while (curLeft -> right && curLeft -> right != cur) {
                curLeft = curLeft -> right;
            }

            // 最右侧节点的右指针没有指向根节点，创建连接并前往下一个左子数
            // 的根节点进行连接操作
            if (!curLeft -> right) {
                curLeft -> right = cur;
                cur = cur -> left;
                continue;
            } else {
                // 左子树的最右侧节点有指向根节点，此时说明我们已经进入到了返回
                // 上层的阶段，不再是一开始的建立连接阶段，同时在回到根节点时我们
                // 应处理完下层节点，直接断开连接即可
                curLeft -> right = nullptr;
            }
            // 返回上层阶段向右走
            cur = cur -> right;
        }
    }
}

// 遍历方式
void preorderMorris(TreeNode* root) {
    if (!root) return;
    TreeNode* cur = root;
    TreeNode* curLeft = nullptr;
    while (cur != nullptr) {
        curLeft = cur -> left;
        if (curLeft != nullptr) {
            while (curLeft -> right != nullptr && curLeft -> right != cur)
                curLeft = curLeft -> right;

            if (curLeft -> right == nullptr) {
                curLeft -> right = cur;
                cur = cur -> left;
                continue;
            } else curLeft -> right = nullptr;
        }
        cur = cur -> right;
    }
}

// Morris前序遍历
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    TreeNode* cur = root;
    TreeNode* curLeft = nullptr;
    while (cur != nullptr) {
        curLeft = cur -> left;
        if (curLeft != nullptr) {
            while (curLeft -> right != nullptr && curLeft -> right != cur)
                curLeft = curLeft -> right;

            if (curLeft -> right == nullptr) {
                curLeft -> right = cur;
                res.push_back(cur -> val);
                cur = cur -> left;
                continue;
            } else curLeft -> right = nullptr;
        } else res.push_back(cur -> val);

        cur = cur -> right;
    }
    return res;
}

// Morris
vector<int> preorderTraversal(TreeNode* root) {
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
                res.push_back(cur -> val);
                curLeft -> right = cur;
                cur = cur -> left;
                continue;
            } else curLeft -> right = nullptr;
        } else res.push_back(cur -> val);
        cur = cur -> right;
    }
    return res;
}