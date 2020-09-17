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

// ������ȱ��� �ݹ�
// ǰ����� (������)

void preTraversal(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;

    vec.push_back(cur -> val); // �У�ͬʱҲ�Ǵ���ڵ��߼��ĵط���do something
    preTraversal(cur -> left, vec); // ��
    preTraversal(cur -> right, vec); // ��
}

// ������� (������)
void midTraversal(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;

    midTraversal(cur -> left, vec); // ��
    vec.push_back(cur -> val); // �У�ͬʱҲ�Ǵ���ڵ��߼��ĵط���do something
    midTraversal(cur -> right, vec); // ��
}

// ������� (������)
void backTraversal(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;

    backTraversal(cur -> left, vec);
    backTraversal(cur -> right, vec);
    vec.push_back(cur -> val);
}

// ������ȱ��� ����
// ǰ����� (������)


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop();
            if (node -> right) st.push(node -> right); // ��
            if (node -> left) st.push(node -> left); // ��
            st.push(node); // ��
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
            if (node -> right) st.push(node -> right); // ��
            st.push(node); // ��
            st.push(NULL);
            if (node -> left) st.push(node -> left); // ��
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
            st.push(node); // ��
            st.push(NULL);
            if (node -> right) st.push(node -> right); // ��
            if (node -> left) st.push(node -> left); // ��
        } else {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node -> val);
        }
    }

    return result;
}

// ������ȱ��� ����
// ��α���

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) { // ����һ��Ҫʹ�ù̶���Сsize����Ҫʹ��que.size()
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node -> val); // �ڵ㴦����߼�
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
