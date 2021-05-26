#include <iostream>
#include <vector>
#include <queue>
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


// review

int res = 0;
int sumNumbers(TreeNode* root) {
    if (!root) return res;
    dfs(root, 0);
    return res;
}

void dfs(TreeNode* root, int val) {
    val = val * 10 + root -> val;
    if (!root -> left && !root -> right) {
        res += val;
        return;
    }

    if (root -> left) dfs(root -> left, val);
    if (root -> right) dfs(root -> right, val);
}


int sumNumbers(TreeNode* root) {
    int res = 0;
    queue<TreeNode*> treeQ;
    queue<int> sumQ;
    if (root) {
        treeQ.push(root);
        sumQ.push(0);
    }
    while (!treeQ.empty()) {
        int size = treeQ.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = treeQ.front();
            treeQ.pop();
            int sum = sumQ.front();
            sumQ.pop();
            sum = sum * 10 + node -> val;
            if (!node -> left && !node -> right) {
                res += sum;
                continue;
            }

            if (node -> left) {
                treeQ.push(node -> left);
                sumQ.push(sum);
            }

            if (node -> right) {
                treeQ.push(node -> right);
                sumQ.push(sum);
            }
        }
    }

    return res;
}


int sumNumbers(TreeNode* root) {
    int res = 0;
    queue<TreeNode*> treeQ;
    queue<int> numQ;
    if (root) {
        treeQ.push(root);
        numQ.push(0);
    }
    while (!treeQ.empty()) {
        TreeNode* node = treeQ.front();
        treeQ.pop();
        int num = numQ.front();
        numQ.pop();
        num = num * 10 + node -> val;
        if (!node -> left && !node -> right) {
            res += num;
            continue;
        }

        if (node -> left) {
            treeQ.push(node -> left);
            numQ.push(num);
        }

        if (node -> right) {
            treeQ.push(node -> right);
            numQ.push(num);
        }
    }
    return res;
}