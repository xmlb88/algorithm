#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> result;
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        double sum = 0;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            sum += node -> val;
            if (node -> left) que.push(node -> left);
            if (node -> right) que.push(node -> right);
        }
        result.push_back(sum / size);
    }
    return result;
}