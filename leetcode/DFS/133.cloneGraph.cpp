#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*> ();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*> ();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// DFS
unordered_map<Node*, Node*> clone;
Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;

    if (clone.count(node)) return clone[node];

    Node* copyNode = new Node(node -> val);
    clone[node] = copyNode;

    for (Node* neighbor : node -> neighbors) {
        copyNode -> neighbors.emplace_back(cloneGraph(neighbor));
    }

    return copyNode;
}

// BFS
Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;
    unordered_map<Node*, Node*> clone;
    queue<Node*> q;
    q.push(node);
    clone[node] = new Node(node -> val);
    while (!q.empty()) {
        auto n = q.front();
        q.pop();
        for (auto neighbor : n -> neighbors) {
            if (!clone.count(neighbor)) {
                clone[neighbor] = new Node(neighbor -> val);
                q.push(neighbor);
            }
            clone[n] -> neighbors.emplace_back(clone[neighbor]);
        }
    }

    return clone[node];
}