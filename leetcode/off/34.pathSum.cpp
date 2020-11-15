#include <iostream>
#include <vector>
#include "tree/treeNode.h"
using namespace std;

// œ»–Ú±È¿˙ + ªÿÀ›
vector<vector<int>> res;
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<int> vec;
    dfs(root, sum, vec);
    return res;
}

void dfs(TreeNode* root, int sum, vector<int>& vec) {
    if (root == NULL) return;

    vec.push_back(root -> val);
    if (sum - root -> val == 0 && !root -> left && !root -> right) {
        res.push_back(vec);
    }
    dfs(root -> left, sum - root -> val, vec);
    dfs(root -> right, sum - root -> val, vec);
    vec.pop_back();
}