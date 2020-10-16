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

// review
// 前序遍历
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        s_serialize(root, s);
        return s;
    }

    void s_serialize(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "#";
            s += ",";
            return;
        }

        s += to_string(root -> val);
        s += ",";
        s_serialize(root -> left, s);
        s_serialize(root -> right, s);
    }

    queue<string> split(string& s, const char flag = ',') {
        istringstream iss(s);
        string str;
        queue<string> nodes;
        while (getline(iss, str, flag)) {
            nodes.push(str);
        }
        return nodes;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes = split(data);
        return s_deserialize(nodes);
    }

    TreeNode* s_deserialize(queue<string>& nodes) {
        if (nodes.empty()) return NULL;
        string first = nodes.front();
        nodes.pop();
        if (first == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(first));
        root -> left = s_deserialize(nodes);
        root -> right = s_deserialize(nodes);
        return root;
    }
};


// 后序遍历

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        s_serialize(root, s);
        return s;
    }

    void s_serialize(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "#";
            s += ",";
            return;
        }
        s_serialize(root -> left, s);
        s_serialize(root -> right, s);
        s += to_string(root -> val);
        s += ",";
    }

    vector<string> split(string& s, const char flag = ',') {
        istringstream iss(s);
        string str;
        vector<string> nodes;
        while (getline(iss, str, flag)) {
            nodes.push_back(str);
        }
        return nodes;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes = split(data);
        return s_deserialize(nodes);
    }

    TreeNode* s_deserialize(vector<string>& nodes) {
        if (nodes.empty()) return NULL;
        string last = nodes.back();
        nodes.pop_back();
        if (last == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(last));
        root -> right = s_deserialize(nodes);
        root -> left = s_deserialize(nodes);
        return root;
    }
};

// 层序遍历

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        stringstream ss;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node == NULL) {
                    ss << "#" << " ";
                    continue;
                }
                ss << node -> val << " ";
                que.push(node -> left);
                que.push(node -> right);
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        stringstream ss(data);
        queue<TreeNode*> que;
        string first;
        ss >> first;
        TreeNode* root = new TreeNode(stoi(first));
        que.push(root);
        while (!que.empty()) {
            TreeNode* parent = que.front();
            que.pop();
            string left;
            ss >> left;
            if (left == "#") {
                parent -> left = NULL;
            } else {
                parent -> left = new TreeNode(stoi(left));
                que.push(parent -> left);
            }

            string right;
            ss >> right;
            if (right == "#") {
                parent -> right = NULL;
            } else {
                parent -> right = new TreeNode(stoi(right));
                que.push(parent -> right);
            }
        }
        return root;
    }
};


// 前序遍历
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // string s;
        stringstream ss;
        s_serialize(root, ss);
        return ss.str();
    }

    void s_serialize(TreeNode* root, stringstream& ss) {
        if (root == NULL) {
            ss << "#" << " ";
            return;
        }

        // s += to_string(root -> val);
        // s += ",";
        ss << root -> val << " ";
        s_serialize(root -> left, ss);
        s_serialize(root -> right, ss);
    }

    // queue<string> split(string& s, const char flag = ',') {
    //     istringstream iss(s);
    //     string str;
    //     queue<string> nodes;
    //     while (getline(iss, str, flag)) {
    //         nodes.push(str);
    //     }
    //     return nodes;
    // }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // queue<string> nodes = split(data);
        stringstream ss(data);
        return s_deserialize(ss);
    }

    TreeNode* s_deserialize(stringstream& ss) {
        if (ss.fail()) return NULL;
        // string first = nodes.front();
        // nodes.pop();
        string first;
        ss >> first;
        if (first == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(first));
        root -> left = s_deserialize(ss);
        root -> right = s_deserialize(ss);
        return root;
    }
};



// 前序遍历
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        s_serialize(root, s);
        return s;
    }

    void s_serialize(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "#";
            s += ",";
            return;
        }

        s += to_string(root -> val);
        s += ",";
        s_serialize(root -> left, s);
        s_serialize(root -> right, s);
    }

    // queue<string> split(string& s, const char flag = ',') {
    //     istringstream iss(s);
    //     string str;
    //     queue<string> nodes;
    //     while (getline(iss, str, flag)) {
    //         nodes.push(str);
    //     }
    //     return nodes;
    // }

    // 2. 使用strtok
    // int main() {
    //     string str = "one two three four five";
    //     char *token = strtok(str.data(), " ")
    //     while (token != NULL) {
    //         cout << token << '\n';
    //         token = strtok(NULL, " ");
    //     }
    // }

    // queue<string> split(string& s, const char* flag = ",") {
    //     queue<string> nodes;
    //     char *token = strtok(s.data(), flag);
    //     while (token != NULL) {
    //         nodes.push(token);
    //         token = strtok(NULL, flag);
    //     }
    //     return nodes;
    // }

    // 3. 
    // void split(const string& s, vector<string>& tokens, const string& delemiters = " ") {
    //     string::size_type lastpos = s.find_first_not_of(delemiters, 0);
    //     string::size_type pos = s.find_first_of(delemiters, lastpos);
    //     while (string::npos != pos || string::npos != lastpos) {
    //         tokens.push_back(s.substr(lastpos, pos - lastpos));
    //         lastpos = s.find_first_not_of(delemiters, pos);
    //         pos = s.find_first_of(delemiters, lastpos);
    //     }
    // }

    queue<string> split(string& s, const string& delemiters = ",") {
        int lastpos = s.find_first_not_of(delemiters, 0);
        int pos = s.find_first_of(delemiters, lastpos);
        queue<string> nodes;
        while (pos != string::npos || lastpos != string::npos) {
            nodes.push(s.substr(lastpos, pos - lastpos));
            lastpos = s.find_first_not_of(delemiters, pos);
            pos = s.find_first_of(delemiters, lastpos);
        }
        return nodes;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes = split(data);
        return s_deserialize(nodes);
    }

    TreeNode* s_deserialize(queue<string>& nodes) {
        if (nodes.empty()) return NULL;
        string first = nodes.front();
        nodes.pop();
        if (first == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(first));
        root -> left = s_deserialize(nodes);
        root -> right = s_deserialize(nodes);
        return root;
    }
};