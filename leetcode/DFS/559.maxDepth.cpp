#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

int dfs(Node* root) {
    if (!root) return 0;
    int max_depth = 0;
    for (auto node : root -> children) {
        max_depth = max(max_depth, maxDepth(node));
    }
    return max_depth + 1;
}

int maxDepth(Node* root) {
    return dfs(root);
}

