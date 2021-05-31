#include <iostream>
#include <vector>
#include <queue>
#include "treeNode.h"
using namespace std;

// TODO:
// WA
void print(vector<TreeNode*>& vec) {
    for (auto t : vec) {
        cout << t -> val << " ";
    }
    cout << endl;
}

void inorderTraversal(TreeNode* root, vector<TreeNode*>& vec) {
    if (root == nullptr) return;
    inorderTraversal(root -> left, vec);
    vec.push_back(root);
    inorderTraversal(root -> right, vec);
}

void recoverTree(TreeNode* root) {
    vector<TreeNode*> vec;
    inorderTraversal(root, vec);
    TreeNode *x = nullptr, *y = nullptr;
    for (int i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] -> val > vec[i + 1] -> val) {
            y = vec[i + 1];
            if (x = nullptr) x = vec[i];
        }
    }
    if (x != nullptr && y != nullptr) {
        swap(x -> val, y -> val);
    }
}

TreeNode* makeTree(queue<int>& q) {
    if (q.empty()) return nullptr;
    int val = q.front();
    q.pop();
    if (val == -1) return nullptr;
    TreeNode* root = new TreeNode(val);
    root -> left = makeTree(q);
    root -> right = makeTree(q);
    return root;
}

int main() {
    vector<int> vec = {1, 3, -1, -1, 2};
    queue<int> q;
    for (auto i : vec) q.push(i);
    recoverTree(makeTree(q));
}