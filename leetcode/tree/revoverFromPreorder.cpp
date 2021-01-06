#include <iostream>
#include <string>
#include "treeNode.h"
using namespace std;

TreeNode* recoverFromPreorder(string S) {
    if (S.empty()) return nullptr;
    TreeNode* root = new TreeNode(S[0]);
    
}