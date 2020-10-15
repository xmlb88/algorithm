#include<iostream>
#include<queue>
using namespace std;

// µÝ¹é
int minDepth(TreeNode* root) {
    if (root == NULL) return 0;
    if (root -> left == NULL && root -> right != NULL) {
        return 1 + minDepth(root -> right);
    }
    if (root -> left != NULL && root -> right == NULL) {
        return 1 + minDepth(root -> left);
    }
    return min(minDepth(root -> left), minDepth(root -> right)) + 1;
}

// µü´ú
int minDepth(TreeNode* root) {
    queue<TreeNode*> que;
    int ans = 0;
    if (root != NULL) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        ans++;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (!node -> left && !node -> right) {
                return ans;
            }
            if (node -> left) que.push(node -> left);
            if (node -> right) que.push(node -> right);
        }
    }
    return ans;
}
