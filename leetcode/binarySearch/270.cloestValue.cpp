#include <iostream>
#include "treeNode.h"
#include <cmath>
using namespace std;

int closestValue(TreeNode* root, double target) {
    int clost = 0;
    double min_distance = ;

    while (root) {
        double distance = fabs(root -> val - target);
        if (distance < min_distance) {
            clost = root -> val;
            min_distance = distance;
        }

        if (target > root -> val) {
            root = root -> right;
        } else if (target < root -> val) {
            root = root -> left;
        } else {
            return root -> val;
        }
    }
    return clost;
}

int closestValue(TreeNode* root, double target) {
    int l = root -> val, r = root -> val;
    while (root) {
        if (target > root -> val) {
            l = root -> val;
            root = root -> right;
        } else if (target < root -> val) {
            r = root -> val;
            root = root -> left;
        } else {
            return root -> val;
        }
    }

    return fabs(target - l) < fabs(target - r) ? l : r;
}