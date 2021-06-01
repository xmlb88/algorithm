#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include "treeNode.h"
using namespace std;


bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        bool has_null = false, has_next = false;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if ((node -> left || node -> right) && has_null) return false;
            if (!node -> left && node -> right) return false;
            if (!node -> left || !node -> right) has_null = true;
            if (node -> left || node -> right) has_next = true;
            if (node -> left) q.push(node -> left);
            if (node -> right) q.push(node -> right);
        }
        if (has_next && size != pow(2, level)) return false;
        ++level;
    }
    return true;
}


// TODO: