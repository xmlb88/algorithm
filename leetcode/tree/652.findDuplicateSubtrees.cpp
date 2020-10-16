#include <iostream>
#include <vector>
#include "treeNode.h"
using namespace std;

unordered_map<string, int> memo;
vector<TreeNode*> result;
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    serializeAndCheck(root);
    return result;
}

string serializeAndCheck(TreeNode* root) {
    if (root == NULL) {
        return "#";
    }

    string left = serializeAndCheck(root -> left);
    string right = serializeAndCheck(root -> right);
    string subTree = left + "," + right + "," + to_string(root -> val);

    if (memo[subTree] == 1) {
        result.push_back(root);
    } 
    memo[subTree] += 1;
    return subTree;
}