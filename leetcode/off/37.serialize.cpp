#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include "tree/treeNode.h"
using namespace std;

class codeC {
public:
    void ss_serialize(TreeNode* root, string& serial) {
        if (!root) {
            serial += "#,";
        } else {
            serial += to_string(root -> val) + ",";
            ss_serialize(root -> left, serial);
            ss_serialize(root -> right, serial);
        }
    }

    string serialize(TreeNode* root) {
        string ss;
        ss_serialize(root, ss);
        return ss;
    }

    TreeNode* deserialize(string data) {
        
    }
};