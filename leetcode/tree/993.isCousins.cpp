#include <iostream>
#include <vector>
#include "treeNode.h"
#include <tuple>
#include <queue>
using namespace std;


int x_val;
TreeNode* x_parent;
int x_depth;
bool x_found = false;

int y_val;
TreeNode* y_parent;
int y_depth;
bool y_found = false;

void dfs(TreeNode* node, int depth, TreeNode* parent) {
    if (!node) return;

    if (node -> val == x_val) {
        tie(x_parent, x_depth, x_found) = make_tuple(parent, depth, true);
    }

    else if (node -> val == y_val) {
        tie(y_parent, y_depth, y_found) = make_tuple(parent, depth, true);
    }

    if (x_found && y_found) return;

    dfs(node -> left, depth + 1, node);
    
    if (x_found && y_found) return;

    dfs(node -> right, depth + 1, node);
}

int isCousins(TreeNode* root, int x, int y) {
    x_val = x;
    y_val = y;
    dfs(root, 0, nullptr);
    return x_depth == y_depth && x_parent != y_parent;
}



int x_val;
TreeNode* x_parent;
int x_depth;
bool x_found = false;

int y_val;
TreeNode* y_parent;
int y_depth;
bool y_found = false;

void dfs(TreeNode* root, int depth, TreeNode* parent) {
    if (!root) return;

    if (root -> val == x_val) {
        tie(x_parent, x_depth, x_found) = make_tuple(parent, depth, true);
    } else if (root -> val == y_val) {
        tie(y_parent, y_depth, y_found) = make_tuple(parent, depth, true);
    }

    if (x_found && y_found) return;

    dfs(root -> left, depth + 1, root);

    if (x_found && y_found) return;

    dfs(root -> right, depth + 1, root);
}

bool isCousins(TreeNode* root, int x, int y) {
    x_val = x;
    y_val = y;
    dfs(root, 0, nullptr);
    return x_depth == y_depth && x_parent != y_parent;
}

bool update(TreeNode* node, int )




// BFS

int x_val;
TreeNode* x_parent;
int x_depth;
bool x_found = false;

int y_val;
TreeNode* y_parent;
int y_depth;
bool y_found = false;

int depth = 0;
void update(TreeNode* node, TreeNode* parent) {
    if (node -> val == x_val) {
        tie(x_parent, x_depth, x_found) = make_tuple(parent, depth, true);
    } else if (node -> val == y_val) {
        tie(y_parent, y_depth, y_found) = make_tuple(parent, depth, true);
    }
}

bool isCousins(TreeNode* root, int x, int y) {
    x_val = x;
    y_val = y;
    update(root, nullptr);
    queue<TreeNode*> q;
    q.push(root);
    ++depth;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node -> left) {
                update(node -> left, node);
                q.push(node -> left);
            }

            if (node -> right) {
                update(node -> right, node);
                q.push(node -> right);
            }

            if (x_found && y_found) break;
        }
        ++depth;
    }
    return x_depth == y_depth && x_parent != y_parent;
}