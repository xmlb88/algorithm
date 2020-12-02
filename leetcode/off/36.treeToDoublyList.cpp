#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// µÝ¹éÖÐÐò±éÀú
class Solution {
public:
    Node *pre = nullptr, *head;
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        dfs(root);
        pre -> right = head;
        head -> left = pre;
        return head;
    }

    void dfs(Node* root) {
        if (!root) return;

        dfs(root -> left);
        if (pre == nullptr) {
            head = root;
            pre = root;
        } else {
            pre -> right = root;
            root -> left = pre;
            pre = root;
        }
        dfs(root -> right);
    }
};