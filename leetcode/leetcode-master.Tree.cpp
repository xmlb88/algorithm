#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 深度优先遍历 递归
// 前序遍历 (中左右)

void preTraversal(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;

    vec.push_back(cur -> val); // 中，同时也是处理节点逻辑的地方，do something
    preTraversal(cur -> left, vec); // 左
    preTraversal(cur -> right, vec); // 右
}

// 中序遍历 (左中右)
void midTraversal(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;

    midTraversal(cur -> left, vec); // 左
    vec.push_back(cur -> val); // 中，同时也是处理节点逻辑的地方，do something
    midTraversal(cur -> right, vec); // 右
}

// 后序遍历 (左右中)
void backTraversal(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;

    backTraversal(cur -> left, vec);
    backTraversal(cur -> right, vec);
    vec.push_back(cur -> val);
}

// 深度优先遍历 迭代
// 前序遍历 (中左右)


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop();
            if (node -> right) st.push(node -> right); // 右
            if (node -> left) st.push(node -> left); // 左
            st.push(node); // 中
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


vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop();
            if (node -> right) st.push(node -> right); // 右
            st.push(node); // 中
            st.push(NULL);
            if (node -> left) st.push(node -> left); // 左
        } else {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node -> val);
        }
    }

    return result;
}

// back
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop();
            st.push(node); // 中
            st.push(NULL);
            if (node -> right) st.push(node -> right); // 右
            if (node -> left) st.push(node -> left); // 左
        } else {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node -> val);
        }
    }

    return result;
}

// 广度优先遍历 队列
// 层次遍历

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) { // 这里一定要使用固定大小size，不要使用que.size()
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node -> val); // 节点处理的逻辑
            if (node -> left) que.push(node -> left);
            if (node -> right) que.push(node -> right);
        }
        result.push_back(vec);
    }
    return result;
}


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node -> val);
            if (node -> left) que.push(node -> left);
            if (node -> right) que.push(node -> right);
        }
        result.push_back(vec);
    }
    return result;
}
