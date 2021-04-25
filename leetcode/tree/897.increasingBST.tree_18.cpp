#include<iostream>
#include<vector>
using namespace std;

TreeNode* increasingBST(TreeNode* root) {
    vector<int> result;
    inorder(root, result);
    return makeTree(result);
}

TreeNode* makeTree(vector<int> result) {
    TreeNode* root;
    TreeNode* parent;
    for (int i = 0; i < result.size(); i++) {
        TreeNode* node = new TreeNode(result[i]);
        if (i == 0) {
            root = node;
            parent = node;
        }
        else {
            parent -> right = node;
            parent = node;
        }
    }
    return root;
}

void inorder(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    inorder(root -> left, result);
    result.push_back(root -> val);
    inorder(root -> right, result);
}


// review 2021年4月25日09:04:03
void inorder(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    inorder(root -> left, result);
    result.push_back(root -> val);
    inorder(root -> right, result);
}

TreeNode* makeTree(vector<int>& result) {
    TreeNode* root;
    TreeNode* parent;

    for (int i = 0; i < result.size(); ++i) {
        TreeNode* node = new TreeNode(result[i]);
        if (i == 0) {
            root = node;
            parent = node;
        } else {
            parent -> right = node;
            parent = node;
        }
    }
    return root;
}

TreeNode* increasingBST(TreeNode* root) {
    if (!root) return root;
    vector<int> result;
    inorder(root, result);
    return makeTree(result);
}

// vector<TreeNode*>
vector<TreeNode*> in;
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root -> left);
    in.push_back(root);
    inorder(root -> right);
}

TreeNode* increasingBST(TreeNode* root) {
    if (!root) return root;
    inorder(root);
    in[0] -> left = nullptr;
    in[in.size() - 1] -> left = nullptr;
    in[in.size() - 1] -> right = nullptr;
    for (int i = 1; i < in.size(); ++i) {
        in[i - 1] -> left = nullptr;
        in[i - 1] -> right = in[i];
    }
    return in[0];
}

// https://leetcode-cn.com/problems/increasing-order-search-tree/solution/di-zeng-shun-xu-cha-zhao-shu-by-leetcode-dfrr/
// 
void inorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    inorder(root -> left, res);
    res.push_back(root -> val);
    inorder(root -> right, res);
}

TreeNode* increasingBST(TreeNode* root) {
    vector<int> res;
    inorder(root, res);

    TreeNode* dummyNode = new TreeNode(-1);
    TreeNode* currNode = dummyNode;
    for (int val : res) {
        currNode -> right = new TreeNode(val);
        currNode = currNode -> right;
    }
    return dummyNode -> right;
}

// 在中序遍历过程中修改节点指向
TreeNode* resNode;
void inorder(TreeNode* node) {
    if (!node) return;
    inorder(node -> left);
    resNode -> right = node;
    node -> left = nullptr;
    resNode = node;
    inorder(node -> right);
}

TreeNode* increasingBST(TreeNode* root) {
    TreeNode* dummyNode = new TreeNode(-1);
    resNode = dummyNode;
    inorder(root);
    return dummyNode -> right;
}