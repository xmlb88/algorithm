#include <iostream>
#include "tree/treeNode.h"
using namespace std;

bool isValidBST(TreeNode* root) {
    return dfs(root, LONG_MAX, LONG_MIN);
}

bool dfs(TreeNode* root, long long max, long long min) {
    if (!root) return true;

    if (root -> val <= min || root -> val >= max) return false;
    return dfs(root -> left, root -> val, min) && dfs(root -> right, max, root -> val);
}

// �������
TreeNode* last_node = nullptr;
bool isValidBST(TreeNode* root) {
    if (!root) return true;

    // ���������ݹ飬���
    if (!isValidBST(root -> left)) return false;

    // �������λ�ã���鵱ǰ�ڵ�
    if (last_node != nullptr && root -> val <= last_node -> val) return false;
    last_node = root;

    // ���������ݹ飬���
    if (!isValidBST(root -> right)) return false;

    return true;
}