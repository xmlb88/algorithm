#include <iostream>
#include <string>
#include <vector>
#include "tree/treeNode.h"
using namespace std;

vector<string> binaryTreePaths(TreeNode* root) {
    string path;
    vector<string> paths;
    dfs(root, path, paths);
    return paths;
}

void dfs(TreeNode* root, string path, vector<string>& paths) {
    if (!root) return;
    
    path += to_string(root -> val);
    if (!root -> left && !root -> right) {
        paths.push_back(path);
        return;
    }

    path += "->";
    dfs(root -> left, path, paths);
    dfs(root -> right, path, paths);
}