#include <iostream>
#include <vector>
#include "treeNode.h"
using namespace std;

int res;
int sumNumbers(TreeNode* root) {
    if (!root) return 0;
    int sum = 0;
    dfs(root, sum);
    return res;
}

void dfs(TreeNode* root, int sum) {
    if (!root) return;
    sum = sum * 10 + root -> val;
    if (!root -> left && !root -> right) {
        res += sum;
    }
    dfs(root -> left, sum);
    dfs(root -> right, sum);
}