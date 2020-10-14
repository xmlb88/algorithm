#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include "treeNode.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        ss_serialize(root, ss);
        return ss.str();
    }

    void ss_serialize(TreeNode* root, stringstream& ss) {
        if (root == NULL) {
            ss << "#" << ",";
            return;
        }

        ss << root -> val << ",";
        ss_serialize(root -> left, ss);
        ss_serialize(root -> right, ss);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        

        return ss_deserialize(nodes);
    }

    TreeNode* ss_deserialize(queue<string>& nodes) {
        if (nodes.empty()) return NULL;

        string first = nodes.front();
        nodes.pop();
        if (first == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(first));
        root -> left = ss_deserialize(nodes);
        root -> right = ss_deserialize(nodes);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

queue<string> split(string )