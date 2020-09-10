#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int farthest = 0;
    for (int i = 0; i < n - 1; i++) {
        // ���ϼ�������������Զ����
        farthest = max(farthest, i + nums[i]);
        // ����������0����ס������
        if (farthest <= i) return false;
    }

    return farthest >= n - 1;
}