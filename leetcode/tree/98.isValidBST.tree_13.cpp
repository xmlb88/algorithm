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

// ´íÎó½â·¨
bool isValidBST(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    if (root -> left != NULL && root -> left -> val >= root -> val) return false;
    if (root -> right != NULL && root -> right -> val <= root -> val) return false;

    if (!isValidBST(root -> left) || !isValidBST(root -> right)) return false;

    return true;

}

// inorderµÝ¹é
bool isValidBST(TreeNode* root) {
    vector<int> inorder;
    inorderTraversal(root, inorder);

    for (int i = 1; i < inorder.size(); i++) {
        if (inorder[i] <= inorder[i - 1]) return false;
    }
    return true;
}

void inorderTraversal(TreeNode* root, vector<int>& inorder) {
    if (root == NULL) return;

    inorderTraversal(root -> left, inorder);
    inorder.push_back(root -> val);
    inorderTraversal(root -> right, inorder);
}


// inorderµü´ú
bool isValidBST(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        if (node != NULL) {
            if (node -> right) st.push(node -> right);
            st.push(node);
            st.push(NULL);
            if (node -> left) st.push(node -> left);
        } else {
            node = st.top();
            st.pop();
            result.push_back(node -> val);
        }
    }

    for (int i = 1; i < result.size(); i++) {
        if (result[i] <= result[i - 1]) return false;
    }

    return true;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!)
}

// µÝ¹é
bool isValidBST(TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
}

bool helper(TreeNode* root, long long lower, long long upper) {
    if (root == NULL) return true;
    if (root -> val <= lower || root -> val >= upper) return false;
    return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
}

// ±ßÖÐÐò±ßÅÐ¶Ï

long pre = LONG_MIN;
bool isValidBST(TreeNode* root) {
    if (root == NULL) return true;

    if (!isValidBST(root -> left)) return false;

    if (root -> val <= pre) {
        return false;
    }

    pre = root -> val;
    return isValidBST(root -> right);
}