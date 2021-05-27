#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
#include "treeNode.h"
using namespace std;


map<int, vector<int>> m;

void dfs(TreeNode* root, int row, int col) {
    if (!root) return;
    m[row].push_back(col);
    dfs(root -> left, row + 1, col - 1);
    dfs(root -> right, row + 1, col + 1);
}

int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    
}