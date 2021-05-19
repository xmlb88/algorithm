#include <iostream>
#include <vector>
#include "listNode.h"
#include <cmath>
#include <algorithm>
using namespace std;

// int getDecimalValue(ListNode* head) {
//     vector<int> nums;
//     while (head) {
//         nums.push_back(head -> val);
//         head = head -> next;
//     }
//     reverse(nums.begin(), nums.end());

//     int res = 0;
//     for (int i = 0; i < nums.size(); ++i) {
//         if (nums[i]) {
//             res += (1 << i);
//             cout << (1 << i) << endl;
//         }
//     }
//     return res;
// }

// https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer/solution/
// ÓÅ»¯
int getDecimalValue(ListNode* head) {
    int num = 0;
    while (head) {
        num = num * 2 + head -> val;
        head = head -> next;
    }
    return num;
}

int main() {
    vector<int> nums = {1,0,0,1,0,0,1,1,1,0,0,0,0,0,0};
    ListNode* dummy = new ListNode(0), *cur = dummy;
    for (int i = 0; i < nums.size(); ++i) {
        cur -> next = new ListNode(nums[i]);
        cur = cur -> next;
    }
    cout << getDecimalValue(dummy -> next) << endl;
}
