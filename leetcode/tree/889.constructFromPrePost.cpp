#include <iostream>
#include <vector>
#include <unordered_map>
#include "treeNode.h"
using namespace std;

// 前序遍历 中左右  后序遍历 左右中
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    return construct(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
}

TreeNode* construct(vector<int>& pre, int pre_i, int pre_j, vector<int>& post, int post_i, int post_j) {
    if (pre_i > pre_j || post_i > post_j) return nullptr;
    TreeNode* root = new TreeNode(pre[pre_i]);
    if (pre_i == pre_j) return root;

    int val = pre[pre_i + 1], len = 0;
    for (int i = post_i; i < post_j; ++i) {
        if (post[i] == val) break;
        ++len;
    }

    root -> left = construct(pre, pre_i + 1, pre_i + len + 1, post, post_i, post_i + len);
    root -> right = construct(pre, pre_i + len + 2, pre_j, post, post_i + len + 1, post_j - 1);
    return root;
}


// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/solution/gen-ju-qian-xu-he-hou-xu-bian-li-gou-zao-er-cha-sh/https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/solution/gen-ju-qian-xu-he-hou-xu-bian-li-gou-zao-er-cha-sh/
// 

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    return make(pre, post, 0, 0, pre.size());
}

TreeNode* make(vector<int>& pre, vector<int>& post, int pre_i, int post_i, int len) {
    if (len == 0) return nullptr;
    TreeNode* root = new TreeNode(pre[pre_i]);
    if (len == 1) return root;
    int N = 0;
    for (int i = post_i; i < post_i + len - 1; ++i) {
        ++N;
        if (post[i] == pre[pre_i + 1]) break;
    }
    root -> left = make(pre, post, pre_i + 1, post_i, N);
    root -> right = make(pre, post, pre_i + N + 1, post_i + N, len - N - 1);
    return root;
}


unordered_map<int, int> m;
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    for (int i = 0; i < post.size(); ++i) {
        m[post[i]] = i;
    }

    return make(pre, post, 0, 0, pre.size());
}

TreeNode* make(vector<int>& pre, vector<int>& post, int pre_i, int post_i, int len) {
    if (len == 0) return nullptr;
    TreeNode* root = new TreeNode(pre[pre_i]);
    if (len == 1) return root;

    int index = m[pre[pre_i + 1]];
    int N = index - post_i + 1;
    root -> left = make(pre, post, pre_i + 1, post_i, N);
    root -> right = make(pre, post, pre_i + 1 + N, post_i + N, len - N - 1);
    return root;
}