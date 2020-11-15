#include <iostream>
#include <vector>
#include "tree/treeNode.h"
using namespace std;

bool verifyPostorder(vector<int>& postorder) {
    return recur(postorder, 0, postorder.size() - 1);
}

bool recur(vector<int>& postorder, int i, int j) {
    // base case
    if (i >= j) return true;

    int p = i;
    while (postorder[p] < postorder[j]) p++;
    int m = p;
    while (postorder[p] > postorder[j]) p++;
    return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);
}