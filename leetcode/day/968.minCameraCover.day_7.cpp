#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// ´íÎó
int minCameraCover(TreeNode* root) {
    queue<TreeNode*> que;
    int count = 0;
    int level = 0;
    if (root != NULL) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        level++;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (level % 2 == 0) count++;
            if (node -> left) que.push(node -> left);
            if (node -> right) que.push(node -> right);
        }
    }
    if (level <= 2) return 1;
    return count;
}