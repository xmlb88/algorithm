#include <iostream>
#include "treeNode.h"
using namespace std;

bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    dfs(root, x);
    int up_node = n - left_node - right_node - 1;
    return left_node > n / 2 || right_node > n / 2 || up_node > n / 2;
}

int left_node, right_node;
int dfs(TreeNode* root, int x) {
    if (!root) return 0;

    int left = dfs(root -> left, x);
    int right = dfs(root -> right, x);

    if (root -> val == x) {
        left_node = left;
        right_node = right;
    }

    return left + right + 1;
}