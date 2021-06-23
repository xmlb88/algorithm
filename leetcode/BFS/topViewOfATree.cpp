#include <iostream>
#include "treeNode.h"
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};

vector<int> solve(Tree* root) {
    if (!root) return {};
    map<int, int> m;
    queue<pair<Tree*, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        auto node = t.first;
        int val = t.second;
        if (m.find(val) == m.end()) {
            m[val] = node -> val;
        }
        if (node -> left) q.push(make_pair(node -> left, val - 1));
        if (node -> right) q.push(make_pair(node -> right, val + 1));
    }

    vector<int> res;
    for (auto& [index, val] : m) {
        res.push_back(val);
    }
    return res;
}