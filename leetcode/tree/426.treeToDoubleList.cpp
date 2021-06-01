#include <iostream>
#include <vector>
#include "treeNode.h"
using namespace std;

class Node {
    int val;
    Node* left;
    Node* right;

    Node() {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr) {}
    Node(int _val, Node* _left, Node* _right) : val(_val), left(_left), right(_right) {}
};

// TODO:
Node* successor(Node* root) {
    if (!root || !root -> right) return nullptr;
    root = root -> right;
    while (root -> left) root = root -> left;
    return root;
}

Node* predecessor(Node* root) {
    if (!root || !root -> left) return nullptr;
    root = root -> left;
    while (root -> right) root = root -> right;
    return root;
}

Node* leftBound;
Node* treeToDoubleList(Node* root) {
    if (!root) return nullptr;


}