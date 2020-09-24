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

    /*****ǰ�����λ��*****/
    // ������������ڵ�����
    node1 -> next = node2;

    // ������ͬ���ڵ�������ӽڵ�
    connectTwoNode(node1 -> left, node1 -> right);
    connectTwoNode(node2 -> left, node2 -> right);
    // ���ӿ�Խ���ڵ�������ӽڵ�
    connectTwoNode(node1 -> right, node2 -> left);
}