#include <iostream>
#include <vector>
#include <unordered_map>
#include "treeNode.h"
using namespace std;

// 1 1,2  // 2 3, 4

unordered_map<int, int> m;
int sum = 0;

void dfs(int depth, int pos, int preSum) {
    int root = depth * 10 + pos;
    if (m.find(root) == m.end()) return;
    preSum += m[root];
    ++depth;
    int lpos = pos * 2 - 1, lchild = depth * 10 + lpos;
    int rpos = pos * 2, rchild = depth * 10 + rpos;
    auto lit = m.find(lchild);
    auto rit = m.find(rchild);
    if (lit == m.end() && rit == m.end()) {
        sum += preSum;
        return;
    }

    if (lit != m.end()) {
        dfs(depth, lpos, preSum);
    }

    if (rit != m.end()) {
        dfs(depth, rpos, preSum);
    }
}

int pathSum(vector<int>& nums) {
    for (int num : nums) {
        m[num / 10] = num % 10;
    }

    dfs(1, 1, 0);
    return sum;
}