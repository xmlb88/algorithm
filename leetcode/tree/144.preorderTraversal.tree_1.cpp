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

// review 2020��10��27��09:09:55

// �ݹ�
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

// ����
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

// ����2
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


// review 2021��5��25��14:33:01
// �ݹ�
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

// ���� stack
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    if (root) st.push(root);
    vector<int> res;
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node -> val);
        // �ҽ���Ƚ�ջ
        if (node -> right) st.push(node -> right);
        if (node -> left) st.push(node -> left);
    }
    return res;
}

// ���� ͨ�ð�
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

// ���� ָ��
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

// ��ͨ���� review
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

// Morris����

// ������ʽ
void preorderMorris(TreeNode* root) {
    if (!root) return;
    TreeNode* cur = root;   // ��ǰ�ڵ�
    TreeNode* curLeft = nullptr;    // ��ǰ�ڵ��������
    while (cur) {
        curLeft = cur -> left;
        // ��ǰ�ڵ�����������ڼ��ɽ�������
        if (curLeft) {
            // �ҵ���ǰ�����������Ҳ�ڵ㣬���Ҳ����������ӷ����ϲ�
            while (curLeft -> right && curLeft -> right != cur) {
                curLeft = curLeft -> right;
            }

            // ���Ҳ�ڵ����ָ��û��ָ����ڵ㣬�������Ӳ�ǰ����һ��������
            // �ĸ��ڵ�������Ӳ���
            if (!curLeft -> right) {
                curLeft -> right = cur;
                cur = cur -> left;
                continue;
            } else {
                // �����������Ҳ�ڵ���ָ����ڵ㣬��ʱ˵�������Ѿ����뵽�˷���
                // �ϲ�Ľ׶Σ�������һ��ʼ�Ľ������ӽ׶Σ�ͬʱ�ڻص����ڵ�ʱ����
                // Ӧ�������²�ڵ㣬ֱ�ӶϿ����Ӽ���
                curLeft -> right = nullptr;
            }
            // �����ϲ�׶�������
            cur = cur -> right;
        }
    }
}

// ������ʽ
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

// Morrisǰ�����
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