#include <iostream>
#include "tree/treeNode.h"
#include <vector>
using namespace std;

vector<vector<int>> result;
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<int> vec;
    helper(root, sum, vec);
    return result;
}

void helper(TreeNode* root, int sum, vector<int>& vec) {
    // base case
    if (root == NULL) return;
    vec.push_back(root -> val);
    sum -= root -> val;
    if (sum == 0 && root -> left == NULL && root -> right == NULL) {
        result.push_back(vec);
        //return;
    }

    // if (sum - root -> val < 0) {
    //     return;
    // }

    helper(root -> left, sum, vec);
    helper(root -> right, sum, vec);
    vec.pop_back();
}

vector<vector<int>> result;
vector<int> vec;
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    dfs(root, sum);
    return result;
}

void dfs(TreeNode* root, int sum) {
    if (root == NULL) return;
    sum -= root -> val;
    vec.push_back(root -> val);
    if (sum == 0 && root -> left == NULL && root -> right == NULL) {
        result.push_back(vec);
        // return;
    }

    // if (sum < 0) return;

    dfs(root -> left, sum);
    dfs(root -> right, sum);
    vec.pop_back();
}


// review 2021��5��27��17:15:56

// ����
vector<vector<int>> res;
vector<int> path;
void dfs(TreeNode* root, int targetSum, int preSum) {
    if (!root) return;
    preSum += root -> val;
    path.push_back(root -> val);
    if (!root -> left && !root -> right && targetSum == preSum) {
        res.push_back(path);
    }

    dfs(root -> left, targetSum, preSum);
    dfs(root -> right, targetSum, preSum);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    dfs(root, targetSum, 0);
    return res;
}