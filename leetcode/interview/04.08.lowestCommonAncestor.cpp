#include <iostream>
#include "tree/treeNode.h"
#include <unordered_map>
using namespace std;

// ��¼���ڵ�
unordered_map<TreeNode*, TreeNode*> father;
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    father[root] = nullptr;
    recordFather(root);

    unordered_map<TreeNode*, bool> visited;
    while (p) {
        visited[p] = true;
        p = father[p];
    }

    while (q) {
        if (visited[q] == true) return q;
        q = father[q];
    }

    return root;
}

void recordFather(TreeNode* root) {
    if(root -> left) {
        father[root -> left] = root;
        recordFather(root -> left);
    }

    if (root -> right) {
        father[root -> right] = root;
        recordFather(root -> right);
    }
}

// �ݹ�
TreeNode* ans;
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, p, q);
    return ans;
}

bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return false;

    bool lson = dfs(root -> left, p, q);
    bool rson = dfs(root -> right, p, q);
    if ((lson && rson) || ((lson || rson) && (root -> val == p -> val || root -> val == q -> val))) {
        ans = root;
    }

    return lson || rson || root -> val == p -> val || root -> val == q -> val;
}

// �ݹ�
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;

    // ����ҵ���p��q��������
    if (root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root -> left, p, q);
    TreeNode* right = lowestCommonAncestor(root -> right, p, q);
    // ���left��right����¼���ҵ��Ľڵ㣬��ô�϶���һ����¼��p����һ����¼��q
    // ���Ƿֱ�����rootΪ�������������У�����root�������ǵ������������
    if (left != nullptr && right != nullptr) return root;

    return (left != nullptr) ? left : right;
}