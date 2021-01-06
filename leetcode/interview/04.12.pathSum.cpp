#include <iostream>
#include "tree/treeNode.h"
using namespace std;

int count = 0;
int pathSum(TreeNode* root, int sum) {
    if (!root) return count;
    dfs(root, sum);
    pathSum(root -> left, sum);
    pathSum(root -> right, sum);
    return count;
}

void dfs(TreeNode* root, int sum) {
    if (!root) return;

    sum -= root -> val;
    if (sum == 0) count++;

    dfs(root -> left, sum);
    dfs(root -> right, sum);
}

// 
int res = 0;
int pathSum(TreeNode* root, int sum) {
    if (!root) return res;

    dfs(root, sum);
    pathSum(root -> left, sum);
    pathSum(root -> right, sum);
    return res;
}

void dfs(TreeNode* root, int sum) {
    if (!root) return;

    sum -= root -> val;
    if (sum == 0) res++;

    dfs(root -> left, sum);
    dfs(root -> right, sum);
    
}

// 
int res = 0;
int pathSum(TreeNode* root, int sum) {
    if (!root) return 0;
    dfs(root, sum);
    pathSum(root -> left, sum);
    pathSum(root -> right, sum);
    return res;
}

void dfs(TreeNode* root, int sum) {
    if (!root) return;

    if (root -> val == sum) res++;
    dfs(root -> left, sum - root -> val);
    dfs(root -> right, sum - root -> val);
}