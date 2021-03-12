#include <iostream>
#include "treeNode.h"
#include <stack>
using namespace std;

// TreeNode* isvalid(const string& preorder, int index) {
//     if (index >= preorder.size()) return true;
//     int lindex = 2 * index + 1;
//     int rindex = 2 * index + 2;

    
// }

// bool isValidSerialization(string preorder) {
//     return isvalid(preorder, 0);
// }

// int main() {
//     string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
//     cout << isValidSerialization(s) << endl;
// }

// 序列中：数字数量 = \#号数量 - 1
// 在最后一个位置之前，数字数量 >= #号数量数字数量
// 由1和2可知，最后一个位置必为#号

// bool isValidSerialization(string preorder) {
//     int n = preorder.size();
//     int num = 0, cnt = 0;
//     if (preorder[n - 1] != '#') return false;

//     int i = 0;
//     while (i < n) {
//         if (preorder[i] == ',') {
//             ++i;
//             continue;
//         }

//         if (preorder[i] == '#') {
//             ++cnt; ++i;
//         } else {
//             while (isdigit(preorder[i])) {
//                 ++i;
//             }
//             ++num;
//         }

//         if (i < n - 1 && num < cnt) return false;
//     }

//     return num == cnt - 1;
// }

bool isValidSerialization(string preorder) {
    int n = preorder.size();
    int i = 0;
    stack<int> stk;
    stk.push(1);
    while (i < n) {
        if (stk.empty()) {
            return false;
        }

        if (preorder[i] == ',') {
            ++i;
        } else if (preorder[i] == '#') {
            stk.top() -= 1;
            if (stk.top() == 0) {
                stk.pop();
            }
            ++i;
        } else {
            while (i < n && preorder[i] != ',') {
                i++;
            }
            stk.top() -= 1;
            if (stk.top() == 0) {
                stk.pop();
            }
            stk.push(2);
        }
    }
    return stk.empty();
}

// 用一个计数器
bool isValidSerialization(string preorder) {
    int n = preorder.size();
    int i = 0, cnt = 1;
    while (i < n) {
        if (cnt == 0) {
            return false;
        }

        if (preorder[i] == ',') {
            ++i;
        } else if (preorder[i] == '#') {
            --cnt;
            ++i;
        } else {
            while (i < n && preorder[i] != ',') {
                ++i;
            }
            ++cnt;
        }
    }
    return cnt == 0;
}



int main() {
    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << isValidSerialization(s) << endl;
}