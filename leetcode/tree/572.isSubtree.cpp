#include <iostream>
#include <vector>
#include "treeNode.h"
#include <string>
using namespace std;

// 序列化比较
bool isMatch;
string t_seria;
bool isSubtree(TreeNode* s, TreeNode* t) {
    isMatch = false;
    t_seria = serialize_t(t);
    serialize_s(s);
    return isMatch;
}

string serialize_t(TreeNode* t) {
    if (t == NULL) {
        return "#";
    }

    string left = serialize_t(t -> left);
    string right = serialize_t(t -> right);

    return left + "," + right + "," + to_string(t -> val);
}

string serialize_s(TreeNode* s) {
    if (s == NULL) {
        return "#";
    }

    string left = serialize_s(s -> left);
    string right = serialize_s(s -> right);

    string s_serial = left + "," + right + "," + to_string(s -> val);
    if (s_serial == t_seria) isMatch = true;
    return s_serial;
}

// 递归
bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    return isSameTree(s, t) || isSubtree(s -> left, t) || isSubtree(s -> right, t);
}

bool isSameTree(TreeNode* s, TreeNode* t) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    if (s -> val != t -> val) return false;
    return isSameTree(s -> left, t -> left) && isSameTree(s -> right, t -> right);
}