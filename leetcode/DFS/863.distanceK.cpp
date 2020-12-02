#include <iostream>
#include <vector>
#include "tree/treeNode.h"
using namespace std;

vector<int> res;
unordered_map<TreeNode*, TreeNode*> father;
vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    father[root] = nullptr;
    recordFather(root);

    TreeNode* cur = target;
    int distance = 0;
    TreeNode* lastNode = nullptr;
    while (cur != nullptr) {
        searchSon(cur, lastNode, K, distance);
        distance++;
        lastNode = cur;
        cur = father[cur];
    }

    return res;
}

void recordFather(TreeNode* root) {
    if (root -> left) {
        father[root -> left] = root;
        recordFather(root -> left);
    }
    if (root -> right) {
        father[root -> right] = root;
        recordFather(root -> right);
    }
}

void searchSon(TreeNode* root, TreeNode* lastNode, int K, int distance) {
    if (root == nullptr) return;
    if (distance == K) {
        res.push_back(root -> val);
        return;
    }

    if (root -> left != lastNode) {
        searchSon(root -> left, target, K, distance + 1);
    }
    if (root -> right != lastNode) {
        searchSon(root -> right, target, K, distance + 1);
    }
}