#include <iostream>
#include <queue>
using namespace std;




// 迭代 与116一样 但递归不同
// 116递归为完美二叉树可以那样
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

// 利用next
Node* connect(Node* root) {
    if (!root) return root;
    Node* cur = root;
    while (cur != NULL) {
        Node* dummy = new Node(0);
        Node* pre = dummy;
        while (cur != NULL) {
            if (cur -> left != NULL) {
                pre -> next = cur -> left;
                pre = pre -> next;
            }
            if (cur -> right != NULL) {
                pre -> next = cur -> right;
                pre = pre -> next;
            }
            cur = cur -> next;
        }
        cur = dummy -> next;
    }
    return root;
}

Node* connect(Node* root) {
    if (!root) return root;
    Node* cur = root;
    while (cur) {
        Node* dummy = new Node(0);
        Node* pre = dummy;
        while (cur) {
            if (cur -> left) {
                pre -> next = cur -> left;
                pre = pre -> next;
            }
            if (cur -> right) {
                pre -> next = cur -> right;
                pre = pre -> next;
            }
            cur = cur -> next;
        }
        cur = dummy -> next;
    }
    return root;
}