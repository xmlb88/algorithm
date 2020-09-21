#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// first version
TreeNode* invertTree (TreeNode* root) {
    if (root == NULL) return root;

    invertTree(root -> left);
    invertTree(root -> right);

    if (root -> left != NULL && root -> right != NULL) {
        TreeNode *tmp = root -> left;
        root -> left = root -> right;
        root -> right = tmp;
    } else if (root -> left == NULL && root -> right != NULL) {
        root -> left = root -> right;
        root -> right = NULL;
    } else if (root -> right == NULL && root -> left != NULL) {
        root -> right = root -> left;
        root -> left = NULL;
    }

    return root;
}

// µÝ¹é ºóÐò
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return root;

    invertTree(root -> left);
    invertTree(root -> right);

    swap(root -> left, root -> right);
    return root;
}

// µÝ¹é Ç°Ðò
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return root;

    swap(root -> left, root -> right);
    invertTree(root -> left);
    invertTree(root -> right);

    return root;
}