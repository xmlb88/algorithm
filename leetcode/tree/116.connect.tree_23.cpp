#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    // if (root == NULL) return NULL;
    queue<Node*> que;
    if (root) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            Node* node = que.front();
            que.pop();
            if (i != size - 1) {
                node -> next = que.front();
            }
            if (node -> left) que.push(node -> left);
            if (node -> right) que.push(node -> right);
        }
    }

    return root;
}

Node* connect(Node* root) {
    if (root == NULL) return NULL;
    connectTwoNode(root -> left, root -> right);
    return root;
}

void connectTwoNode(Node* node1, Node* node2) {
    if (node1 == NULL || node2 == NULL) return;

    /*****前序遍历位置*****/
    // 将传入的两个节点连接
    node1 -> next = node2;

    // 连接相同父节点的两个子节点
    connectTwoNode(node1 -> left, node1 -> right);
    connectTwoNode(node2 -> left, node2 -> right);
    // 连接跨越父节点的两个子节点
    connectTwoNode(node1 -> right, node2 -> left);
}


// review
// 完美二叉树
// 递归
Node* connect(Node* root) {
    if (!root) return root;
    connectNode(root -> left, root -> right);
    return root;
}

void connectNode(Node* left, Node* right) {
    if (!left || !right) return;
    left -> next = right;

    connectNode(left -> left, left -> right);
    connectNode(left -> right, right -> left);
    connectNode(right -> left, right -> right);
}

// 迭代
Node* connect(Node* root) {
    if (!root) return root;
    queue<Node*> que;
    que.push(root);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            Node* pre = que.front();
            que.pop();
            if (i != size - 1) {
                pre -> next = que.front();
            }
            if (pre -> left) que.push(pre -> left);
            if (pre -> right) que.push(pre -> right);
        }
    }
    return root;
}