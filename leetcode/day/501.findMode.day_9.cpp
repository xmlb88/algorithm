#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> record;
    queue<TreeNode*> que;
    vector<int> result;
    int count = 0;

    if (root) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            record[node -> val]++;
            count = max(count, record[node -> val]);
            if (node -> left) que.push(node -> left);
            if (node -> right) que.push(node -> right);
        }
    }

    for (auto it = record.begin(); it != record.end(); it++) {
        if (it -> second == count) {
            result.push_back(it -> first);
        }
    }

    return result;
}

vector<int> result;
int count = 0;
int max_count = 0;
int current = 0;

vector<int> findMode(TreeNode* root) {
    helper(root);
    return result;
}

void helper(TreeNode* root) {
    if (root == NULL) return;

    helper(root -> left);
    int node_val = root -> val;
    if (node_val == current) {
        count++;
    } else {
        current = node_val;
        count = 1;
    }

    if (count == max_count) {
        result.push_back(node_val);
    } else if (count > max_count) {
        result.clear();
        result.push_back(node_val);
        max_count = count;
    }

    helper(root -> right);
}