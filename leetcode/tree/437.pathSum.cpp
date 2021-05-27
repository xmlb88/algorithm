#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include "treeNode.h"
using namespace std;

vector<int> path;
int count = 0;

void calculater(int targetSum) {
    int sum = 0;
    for (int i = path.size() - 1; i >= 0; --i) {
        sum += path[i];
        if (sum == targetSum) ++count;
    }
}

void dfs(TreeNode* root, int targetSum) {
    if (root -> left) {
        path.push_back(root -> left -> val);
        dfs(root -> left, targetSum);
        calculater(targetSum);
        path.pop_back();
    }

    if (root -> right) {
        path.push_back(root -> right -> val);
        dfs(root -> right, targetSum);
        calculater(targetSum);
        path.pop_back();
    }
}

int pathSum(TreeNode* root, int targetSum) {
    if (!root) return 0;
    path.push_back(root -> val);
    calculater(targetSum);
    dfs(root, targetSum);
    return count;
}


// Ç°×ººÍ + hash + »ØËÝ

unordered_map<int, int> m;
int res = 0;

void dfs(TreeNode* root, int targetSum, int preSum) {
    if (!root) return;
    preSum += root -> val;
    res += m[preSum - targetSum];
    ++m[preSum];
    dfs(root -> left, targetSum, preSum);
    dfs(root -> right, targetSum, preSum);
    --m[preSum];
}

int pathSum(TreeNode* root, int targetSum) {
    ++m[0];
    dfs(root, targetSum, 0);
    return res;
}

// µÝ¹é
int sumSearch(TreeNode* root, int sum, int targetSum) {
    if (!root) return 0;
    sum += root -> val;
    return (sum == targetSum) + sumSearch(root -> left, sum, targetSum) +
        sumSearch(root -> right, sum, targetSum);
}

int pathSum(TreeNode* root, int targetSum) {
    if (!root) return 0;
    return sumSearch(root, 0, targetSum) + pathSum(root -> left, targetSum)
        + pathSum(root -> right, targetSum);
}