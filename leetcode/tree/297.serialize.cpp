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
// 先序遍历
class Codec {
public:

    queue<string> split(string& s, const char flag = ",") {
        istringstream iss(s);
        queue<string> que;
        string res;
        while (getline(iss, res, flag)) {
            que.push(res);
        }
        return que;
    }

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
        queue<string> nodes = split(data, ',');
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

// 后序遍历
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        ss_serialize(root, s);
        return s;
    }

    void ss_serialize(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "#";
            s += ",";
            return;
        }

        ss_serialize(root -> left, s);
        ss_serialize(root -> right, s);
        s += to_string(root -> val);
        s += ",";
    }

    vector<string> split(string s, const char flag = ',') {
        vector<string> res;
        istringstream iss(s);
        string str;
        while (getline(iss, str, flag)) {
            res.push_back(str);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes = split(data);
        return ss_deserialize(nodes);
    }

    TreeNode* ss_deserialize(vector<string>& nodes) {
        if (nodes.empty()) return NULL;

        // 从后往前取元素
        string last = nodes.back();
        nodes.pop_back();
        if (last == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(last));
        root -> right = ss_deserialize(nodes);
        root -> left = ss_deserialize(nodes);
        return root;
    }
};

// 层序遍历
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        string s;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();

            if (cur == NULL) {
                s += "#";
                s += ",";
                continue;
            }

            s += to_string(cur -> val);
            s += ",";

            que.push(cur -> left);
            que.push(cur -> right);
        }
        return s;
    }

    vector<string> split(string& s, const char flag = ',') {
        vector<string> res;
        istringstream iss(s);
        string str;
        while (getline(iss, str, flag)) {
            res.push_back(str);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        vector<string> nodes = split(data);
        queue<TreeNode*> que;
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        que.push(root);
        for (int i = 1; i < nodes.size(); ) {
            TreeNode* parent = que.front();
            que.pop();
            string left = nodes[i++];
            if (left != "#") {
                parent -> left = new TreeNode(stoi(left));
                que.push(parent -> left);
            } else {
                parent -> left = NULL;
            }

            string right = nodes[i++];
            if (right != "#") {
                parent -> right = new TreeNode(stoi(right));
                que.push(parent -> right);
            } else {
                parent -> right = NULL;
            }
        }
        return root;
    }
};

// 层序遍历 + stringstream
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        queue<TreeNode*> que;
        stringstream ss;
        que.push(root);
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();

            if (cur == NULL) {
                ss << "# ";
                continue;
            }

            ss << cur -> val << " ";
            que.push(cur -> left);
            que.push(cur -> right);
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        stringstream ss(data);
        string node;
        ss >> node;
        TreeNode* root = new TreeNode(stoi(node));
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* parent = que.front();
            que.pop();
            string left;
            ss >> left;
            if (left != "#") {
                parent -> left = new TreeNode(stoi(left));
                que.push(parent -> left);
            } else {
                parent -> left = NULL;
            }

            string right;
            ss >> right;
            if (right != "#") {
                parent -> right = new TreeNode(stoi(right));
                que.push(parent -> right);
            } else {
                parent -> right = NULL;
            }
        }
        return root;
    }
};