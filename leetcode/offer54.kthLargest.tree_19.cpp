#include<iostream>
#include<vector>
using namespace std;

// �����������
int res = 0, l = 0;
int kthLargest(TreeNode* root, int k) {
    helper(root, k);
    return res;
}

void helper(TreeNode* root, int k) {
    if (root == NULL) return;
    helper(root -> right, k);
    l++;
    if (l == k) {
        res = root -> val;
        return;
    }
    helper(root -> left, k);
    return;
}

