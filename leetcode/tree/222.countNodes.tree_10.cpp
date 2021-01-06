#include<iostream>
#include<queue>
using namespace std;

// �ݹ�
int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    return countNodes(root -> left) + countNodes(root -> right) + 1;
}

// ����
int countNodes(TreeNode* root) {
    int ans = 0;
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        ans += size;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node -> left) que.push(node -> left);
            if (node -> right) que.push(node -> right);
        }
    }
    return ans;
}

// ���ֲ���



// review
int countNodes(TreeNode* root) {
    if (!root) return 0;

    return countNodes(root -> left) + countNodes(root -> right) + 1;
}

// ���ò���
int countNodes(TreeNode* root) {
    if (!root) return 0;
    int left = countLevel(root -> left);
    int right = countLevel(root -> right);
    if (left == right) {
        return countNodes(root -> right) + (1 << left);
    } else {
        return countNodes(root -> left) + (1 << right);
    }
}

int countLevel(TreeNode* root) {
    int level = 0;
    while (root) {
        level++;
        root = root -> left;
    }
    return level;
}

// ���ַ�
// ������������
int countLevel(TreeNode* root) {
    int level = 0;
    while (root) {
        level++;
        root = root -> left;
    }
    return level;
}

bool is_exist(TreeNode* root, int index, int depth) {
    TreeNode* node = root;
    while (depth) {
        // ���һ��ֽ���
        int mid = ((1 << depth) >> 1);
        if (index > mid) {
            index -= mid;
            node = node -> right;
        } else {
            node = node -> left;
        }
        depth -= 1;
    }
    return node != nullptr;
}

int countNodes(TreeNode* root) {
    if (!root) return 0;

    // ���������
    int depth = countLevel(root);
    int depth_prev = depth - 1;

    int start = 1, end = (1 << depth_prev), mid = 0;
    while (start <= end) {
        mid = start + ((end - start) >> 1);
        if (is_exist(root, mid, depth_prev)) start = mid + 1;
        else end = mid - 1;
    }

    int ret = (1 << depth_prev) - 1 + start - 1;
    return ret;
}

// copy other
int countLevels(TreeNode* root) {
    int levels = 0;
    while (root) {
        root = root->left; levels += 1;
    }
    return levels;
}

/*
* ���ܣ� �ж����һ���index�������Ƿ����
* root�� ���������ڵ�
* index���ж����һ������Ϊindex�Ľڵ��Ƿ����, ������Χ��[1, 2^depth]
* depth�������ڶ�������, ������Ϊ�����������һ��Ľڵ������� 2^depth
*/
bool is_exist(TreeNode* root, int index, int depth) {
    TreeNode* node = root;
    while (depth) {
        // ���һ��ֽ���
        int mid = ((1 << depth) >> 1);
        if (index > mid) {
            // ���������������Ҫ��������ֵ
            index -= mid;
            node = node->right;
        }
        else {
            node = node->left;
        }
        depth -= 1;
    }
    return node != nullptr;
}

int countNodes(TreeNode* root) {
    // 3. ���ֲ���
    if (root == nullptr) return 0;
    // ���������
    int depth = countLevels(root);
    // �����ڶ������
    int depth_prev = depth - 1;

    int start = 1, end = (1 << depth_prev), mid = 0;
    while (start <= end) {
        mid = start + ((end - start) >> 1);
        if (is_exist(root, mid, depth_prev)) start = mid + 1;
        else end = mid - 1;
    }
    // start - 1Ϊ���һ��ڵ���
    int ret = (1 << depth_prev) - 1 + start - 1;
    return ret;
}
